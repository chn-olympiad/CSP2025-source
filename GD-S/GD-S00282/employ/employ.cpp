#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i)
#define SZ(x) ((int)x.size())

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,m,c[maxn],p[maxn];
char s[maxn];
inline void solve(){
	scanf("%d%d%s",&n,&m,s+1);
	rep(i,1,n) scanf("%d",&c[i]),p[i]=i;
	int res=0;
	do{
		int cnt=0,r=0;
		rep(i,1,n){
			if(cnt>=c[p[i]]||s[i]=='0'){
				cnt++;
			}
			else r++;
		}
		res+=r>=m;
	}while(next_permutation(p+1,p+1+n));
	printf("%d\n",res);
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int _=1;
//	scanf("%d",&_);
	while(_--) solve();
}

