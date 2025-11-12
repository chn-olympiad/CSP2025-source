#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int c[505],m,a[505],n,sum[505],ans,f[505];
string s;
//void dfs(int p){
//	if (p==n+1){
//		int cnt=0,cnt2=0;
//		for (int i=1;i<=n;++i){
//			if (cnt>c[a[i]]||s[a[i]-1]=='0')cnt++;
//			else cnt2++;
//			//cout<<a[i]<<" ";
//		}
//		if (cnt2>=m){
////			for (int i=1;i<=n;++i)cout<<a[i]<<" ";
////			cout<<'\n';
////			cout<<cnt2<<'\n';
//			ans++;
//		}
//		//cout<<'\n';
//		return;
//	}
//	for (int i=1;i<=n;++i){
//		if (!f[i]){
//			a[p]=i;
//			f[i]=1;
//			dfs(p+1);
//			a[p]=0,f[i]=0;
//		}
//	}
//	
//}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	long long ans=1;
	for (int i=1;i<=n;++i)ans=ans*i%mod;
	cout<<(ans%mod);
}
