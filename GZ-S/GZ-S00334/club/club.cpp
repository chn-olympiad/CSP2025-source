// GZ-S00334 王曦 贵阳华师一学校 
#include <bits/stdc++.h>

#define x first
#define y second
#define pb emplace_back
#define upb upper_bound
#define lowb lower_bound
#define fil(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

int rd() {
	int x=0; bool f=0; char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}

typedef long long LL;
typedef vector<int> VI;
typedef unsigned int ull; 
typedef pair<int,int> PII;

const int N=1e5+10;

int n;
int a[N][3],id[N];
int b[N],m;
int ct[10];

void solve()
{
	int ans=0;
	n=rd(); rep(i,0,3) ct[i]=0; 
	rep(i,1,n) rep(j,0,2) a[i][j]=rd();
	rep(i,1,n) {
		int t=max(max(a[i][0],a[i][1]),a[i][2]);
		rep(j,0,2) if(a[i][j]==t) ct[j]++,id[i]=j;
		ans+=t;
	}
	int p=-1;
	rep(i,0,2) if(ct[i]>n/2) p=i;
	if(~p) {
		m=0;
		rep(i,1,n) if(id[i]==p) {
			int t=0; rep(j,0,2) if(j!=p) t=max(t,a[i][j]);
			b[++m]=a[i][p]-t;
		}
		sort(b+1,b+1+m);
		rep(i,1,m-n/2) ans-=b[i];
	}
	printf("%d\n",ans);
}

signed main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T=rd();
	while(T--) solve();
	
	return 0;
}

