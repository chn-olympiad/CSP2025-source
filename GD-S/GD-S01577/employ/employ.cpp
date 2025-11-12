#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=505,mod=998244353;

int n,m,a[N];
LL jie[N],f[N],dp[N][N];
string s;
bool vis[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	jie[0]=1;
	bool flag=true;
	int numm=0,num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) numm++;
		if(s[i-1]-'0') vis[i]=true;
		else flag=false;
		jie[i]=jie[i-1]*i%mod;
	}
	sort(a+1,a+1+n);
	if(n==m){
		if(!flag) cout<<"0";
		else cout<<jie[n-1]*(n-numm)%mod;
		return 0;
	}else if(m==1){
		numm=0;
		LL ans=1;
		for(int i=1,j=1;i<=n;i++){
			if(vis[i]){
				while(j<=n&&a[j]<=i-1) j++;
				ans=ans*(j-1-numm)%mod;
				numm++;
			}
		}
		cout<<(jie[n]+mod-ans*jie[n-numm]%mod)%mod;
		return 0;
	}
	cout<<"0";
//	f[0]=1;
//	for(int i=1,j=1;i<=n;i++){
//		if(vis[i]){
//			while(j<=n&&a[j]<=i-1) j++;
//			f[i]=f[i-1]*(j-1-num)%mod;
//			num++;
//		}else f[i]=f[i-1];
//	}
//	for(i=1;i<=n;i++){
//		if(vis[i]) num++;
//		f[i]=f[i]*jie[i-num]%mod;
//	}
//	for(int i=n;i;i--){
//		for(int j=min(i-1,num-1),p=n;j;j--){
//			while(a[p]>j) p--;
//		}
//	}
	return 0;
} 
