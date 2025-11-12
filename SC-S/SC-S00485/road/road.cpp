#include<bits/stdc++.h>
#define int long long
using namespace std;

//inline int in(){
//	int x=0,t=1;char c=getchar();
//	while(c<'0'||c>'9'){if(c=='-')t=-t;c=getchar();}
//	while('0'<=c&&c<='9')x=x*10+(c^48),c=getchar();
//	return x*t;
//}
//inline void out(int x){
//	if(x<0)putchar('-'),x=-x;
//	if(x>9)out(x/10);
//	putchar(x%10^48);
//}
const int zj=1e7+10;
int n,m,k,fa[zj],mi=LONG_LONG_MAX,res;
struct node{
	int u,vv,val;
}bian[zj];
bool cmp(node a,node b){
	return a.val<b.val;
}
int get(int x){
//	cout<<1;
	return fa[x]=(x==fa[x]?x:get(fa[x]));
}
vector<node> q;
int cnt_q,cnt_b;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k); 
//	n=in(),m=in(),k=in();
	for(int a,b,v,i=1;i<=m;++i){
		scanf("%lld%lld%lld",&a,&b,&v);
//		a=in(),b=in(),v=in();
		bian[i].u=a,bian[i].vv=b,bian[i].val=v;
	}
	sort(bian+1,bian+1+n,cmp);
	for(int c,i=1;i<=k;++i){
		for(int j=0;j<=n;++j){
			fa[j]=j;
		}
		scanf("%lld",&c);
//		c=in();
//		cout<<4456451;
		res=c;
		cnt_q=0,cnt_b=1;
		q.clear();
		for(int v,j=1;j<=n;++j){
			scanf("%lld",&v);
//			v=in();
			q.push_back({0,j,v});
		}
		sort(q.begin(),q.end(),cmp);
		for(int x,y,v,j=1;j<=n+m;++j){
			if(q[cnt_q].val<bian[cnt_b].val){
				x=q[cnt_q].u,y=q[cnt_q].vv;
				v=q[cnt_q].val;
				++cnt_q;
			}
			else{
				x=bian[cnt_b].u,y=bian[cnt_b].vv;
				v=bian[cnt_b].val;
				++cnt_b;
			}
			int fax=get(x),fay=get(y);
			if(fax!=fay){
				res+=v;
				fa[fax]=y;
			}
		}
		if(res<mi)mi=res;
//		mi=min(res,mi);
	}
	printf("%lld",mi);
//	out(mi);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


13
*/