#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int a[N],c[N],g[N];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		a[i]=ch-'0';
	}
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)fl=0;
	}
//	for(int i=1;i<=n;i++)cout<<c[i]<<" ";
//	cout<<endl;

	if(n<=18){
		for(int i=1;i<=n;i++)g[i]=i;
		int ans=0;
		do{
			int now=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(c[g[i]]<=now)now++;
				else if(a[i])cnt++;
				else now++;
	//			cout<<g[i]<<" "<<now<<endl;
			}
	//		cout<<endl;
			if(cnt>=m)ans++;
			ans%=mod;
		}while(next_permutation(g+1,g+1+n));
		cout<<ans;
		return 0;
	}
	else if(fl){
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	else {
		for(int i=1;i<=n;i++)g[i]=i;
		int ans=0;
		do{
			int now=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(c[g[i]]<=now)now++;
				else if(a[i])cnt++;
				else now++;
	//			cout<<g[i]<<" "<<now<<endl;
			}
	//		cout<<endl;
			if(cnt>=m)ans++;
			ans%=mod;
		}while(next_permutation(g+1,g+1+n));
		cout<<ans;
		return 0;
	}
	return 0;
}
