#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int MAXN=505;
const ll MOD=998244353;
int n,m;
int s[MAXN],c[MAXN];
void add(int &x,int y){
	x=(x+y);
	if(x>=MOD){
		x-=MOD;
	}
}
#define lb(x) ((x)&(-x))
namespace Baoli1{
	int f[2][(1<<18)+5][19];
	
	void Do(){
		f[0][0][0]=1;
		rep(i,1,n){
			rep(x,0,i){
				rep(p,1,(1<<n)-1){
					int P=p;
					while(P){
						int j=lb(P);
						P^=j;
						j=__lg(j)+1;
						int lp=p^(1<<(j-1));
						if(s[i]==0&&x>0){
							add(f[1][p][x],f[0][lp][x-1]);
						}else if(s[i]==1){
							if(x<c[j]){
								add(f[1][p][x],f[0][lp][x]);
							}else if(x>c[j]){
								add(f[1][p][x],f[0][lp][x-1]);
							}
						}
					}
				};
			};
			rep(x,0,i){
				rep(p,1,(1<<n)-1){
					f[0][p][x]=f[1][p][x];
					f[1][p][x]=0;
				};
			};
		};
		int ans=0;
		rep(x,0,n-m){
			add(ans,f[0][(1<<n)-1][x]);
		};
		cout<<ans<<'\n';
		exit(0);
	};
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	rep(i,1,n){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	};
	rep(i,1,n){
		cin>>c[i];
	};
	Baoli1::Do();
	return 0;
}
