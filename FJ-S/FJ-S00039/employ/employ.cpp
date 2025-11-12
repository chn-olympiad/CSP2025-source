#include<bits/stdc++.h>
#define int long long
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m,s[N],c[N],f[530010][20];
signed main(){
	qwq;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string S;
	cin>>S;
	for(int i=1;i<=n;i++)s[i]=S[i-1]-'0';
//	for(int i=1;i<=n;i++){
//		cout<<s[i]<<" ";
//	}
//	cout<<"\n";
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			if(s[i]==0||c[i]==0){
				cout<<"0";
				return 0;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int sum=0;
		for(int j=0;j<n;j++)sum+=((i>>j)&1);
		for(int j=0;j<n;j++){
			if((i>>j)&1==0)continue;
//			cout<<sum<<"\n";
			int S=i^(1<<j);
			if(!s[sum]){
				for(int k=0;k<n;k++)(f[i][k+1]+=f[S][k])%=mod;
				continue;
			}
			for(int k=0;k<n;k++){
				if(k>=c[j+1])(f[i][k+1]+=f[S][k])%=mod;
			}
			for(int k=0;k<=n;k++){
				if(k<c[j+1])(f[i][k]+=f[S][k])%=mod;
			}
		}
	}
//	for(int j=1;j<(1<<n);j++){
//		for(int i=0;i<=n;i++)cout<<f[j][i]<<" ";
//		cout<<"\n";
//	}
	
	
	int ans=0;
	for(int i=0;i<=n-m;i++)(ans+=f[(1<<n)-1][i])%=mod;
	cout<<ans;
	return 0;
}

