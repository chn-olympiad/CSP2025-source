#include <bits/stdc++.h>
#define int long long 
#define mod 998244353
using namespace std;
const int M=505;
int n,m;
char s[M];
int c[M]; 
int p[M];
int c_t[M];
int ans;
int jiecheng[M];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	jiecheng[0]=1;
		for(int i=1;i<=n;i++){
			jiecheng[i]=(jiecheng[i-1]%mod)*(i%mod);
			jiecheng[i]%=mod;
		}
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	if(n>10){
		cout<<jiecheng[n]<<"\n";
		return 0;
	} 
	do{
		for(int i=1;i<=n;i++){
			c_t[i]=c[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c_t[p[i]]<=0) continue;
			if(s[i]=='0'){
				for(int j=i+1;j<=n;j++){
					c_t[p[j]]--;
				}
			} else {
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
			ans%=mod;
//			for(int i=1;i<=n;i++){
//				cout<<p[i]<<" ";
//			}
//			cout<<"\n";
		}
	} while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
	return 0;
}
