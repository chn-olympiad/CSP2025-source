#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=500,mod=998244353;

int n,m;
char s[N+2];
int c[N+1];
//ll f[N+1][N+1][N+1];
ll ans;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	if(n>10){
		bool f=1;
		for(int i=1;i<=n;i++) if(s[i]=='0') f=0;
		if(f||m==1){
			ans=1;
			for(int i=1;i<=n;i++) ans=ans*i%mod;
			cout<<ans<<endl;
		}else cout<<0<<endl;
	}
	else{
		int p[n+1];
		for(int i=1;i<=n;i++) p[i]=i;
		do{
			int t=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0') continue;
				if(i-1-t>=c[p[i]]) continue;
				t++;
			}
			if(t>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<endl;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			for(int k=0;k<=i;k++){
//				if(s[i]=='0'){
//					f[i][j][k]=(f[i-1][j-1][k]+f[i-1][j][k]*(j-i+1))%mod;
//				}else{
//					
//					
//				}
//			}
//		}
//	}
	return 0;
}