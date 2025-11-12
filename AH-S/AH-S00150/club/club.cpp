#include<bits/stdc++.h>
#define up(i,l,r) for(int i=l,END##i=r;i<=END##i;i++)
#define dn(i,l,r) for(int i=l,END##i=r;i>=END##i;i--)
#define ve vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define great greater<int>
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
using namespace std;
const int INF=0x3f3f3f3f,N=1e5+7;
struct node{
	int a,b,c;
}a[N];
int n;
pii b[N];
namespace sol{
	i64 read(){
		i64 x=0,f=0;
		char c=getchar();
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return f?-x:x;
	}
	void write(i64 x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void Dianaqwq(){
		n=read();
		up(i,1,n){
			int x=read(),y=read(),z=read();
			a[i].a=x,a[i].b=y,a[i].c=z;
			if(x>y) swap(x,y);
			if(x>z) swap(x,z);
			if(y>z) swap(y,z);
			b[i]={z-y,i};
		}
		sort(b+1,b+n+1,greater<pii>());
		i64 ans=0,xa=0,xb=0,xc=0;
		up(i,1,n){
			int x=b[i].se;
			if(a[x].a>=a[x].b&&a[x].a>=a[x].c){
				if(xa<n/2) ans+=a[x].a,xa++;
				else ans+=max(a[x].c,a[x].b);
			}
			else if(a[x].b>=a[x].a&&a[x].b>=a[x].c){
				if(xb<n/2) ans+=a[x].b,xb++;
				else ans+=max(a[x].c,a[x].a);
			}
			else if(a[x].c>=a[x].b&&a[x].c>=a[x].a){
				if(xc<n/2) ans+=a[x].c,xc++;
				else ans+=max(a[x].a,a[x].b);
			}
		}
		write(ans),puts("");
	}
}
using namespace sol;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();while(T--) Dianaqwq();
	return 0;
}
