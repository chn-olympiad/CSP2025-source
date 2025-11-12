#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define N 100005
#define int long long
using namespace std;
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int x=0;
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int INF=1e18;
int T,n,ans;
struct node{
	int a,b,c,d;
}p[N],a[N],b[N],c[N];
int cnta,cntb,cntc;
bool cmp(node A,node B){
	return A.d>B.d;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	int mx,m;
	while(T--){
		scanf("%lld",&n); m=n/2;
		for(int i=1;i<=n;i++) p[i].a=read(),p[i].b=read(),p[i].c=read();
		ans=0;
		cnta=cntb=cntc=0;
		for(int i=1;i<=n;i++){
			mx=max({p[i].a,p[i].b,p[i].c});
			ans+=mx;
			if(mx==p[i].a) a[++cnta]=p[i],a[cnta].d=p[i].a-max(p[i].b,p[i].c);
			else if(mx==p[i].b) b[++cntb]=p[i],b[cntb].d=p[i].b-max(p[i].a,p[i].c);
			else c[++cntc]=p[i],c[cntc].d=p[i].c-max(p[i].a,p[i].b);
		}
		sort(a+1,a+1+cnta,cmp);
		sort(b+1,b+1+cntb,cmp);
		sort(c+1,c+1+cntc,cmp);
//		for(int i=1;i<=cnta;i++) cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl; cout<<endl;
//		for(int i=1;i<=cntb;i++) cout<<b[i].a<<" "<<b[i].b<<" "<<b[i].c<<endl; cout<<endl;
//		for(int i=1;i<=cntc;i++) cout<<c[i].a<<" "<<c[i].b<<" "<<c[i].c<<endl; cout<<endl;
		if(cntc==0&&(n&1)){
			int res=INF;
			for(int i=1;i<=cnta;i++) res=min(res,a[i].a-a[i].c);
			for(int i=1;i<=cntb;i++) res=min(res,b[i].b-b[i].c);
			write(ans-res),putchar('\n');
			continue;
		}
		else if(cntb==0&&(n&1)){
			int res=INF;
			for(int i=1;i<=cnta;i++) res=min(res,a[i].a-a[i].b);
			for(int i=1;i<=cntc;i++) res=min(res,c[i].c-c[i].b);
			write(ans-res),putchar('\n');
			continue;
		}
		else if(cnta==0&&(n&1)){
			int res=INF;
			for(int i=1;i<=cntb;i++) res=min(res,b[i].b-b[i].a);
			for(int i=1;i<=cntc;i++) res=min(res,c[i].c-c[i].a);
			write(ans-res),putchar('\n');
			continue;
		}
		while(cnta>m){
			ans-=a[cnta].d;
			cnta--;
		}
		while(cntb>m){
			ans-=b[cntb].d;
			cntb--;
		}
		while(cntc>m){
			ans-=c[cntc].d;
			cntc--;
		}
		write(ans),putchar('\n');
	}
	return 0;
}
