#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,m,k,fa[maxn],len=0,flag[maxn],u[maxn],v[maxn],w[maxn];
long long ret=0;
map<int,map<int,int> > mp;
struct node{
	int l,r,v;
};
node pic[maxn];
void add(int x,int y,int z){
	if(x==y) return;
	node tep; tep.l=x; tep.r=y; tep.v=z;
	pic[++len]=tep;
	return ;
}
bool cmp(node a,node b){
	return a.v<b.v;
}
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]); 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		add(u[i],v[i],w[i]);	
	}
	long long pre=0,mx=1e9;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(pic+1,pic+len+1,cmp);
	int pcnt=0;
	long long pret=0;
	for(int j=1;j<=n;j++){
		if(pcnt==n-1) break;
		int px=pic[j].l,py=pic[j].r,pv=pic[j].v;
		int tepx=find(px);
		int tepy=find(py);
		if(tepx!=tepy){
			fa[tepx]=tepy;
			pret+=pv;
			pcnt++;
		}
	}
	mx=min(mx,pret);
	for(int i=1;i<=k;i++){
		fa[n+i]=n+i;
		for(int i=1;i<=n;i++) fa[i]=i;
		int tepv,val,cnt=0; long long ret=0;
		scanf("%d",&tepv);
		ret=pre+tepv; pre=ret;
		for(int j=1;j<=n;j++){
			scanf("%d",&val);
			add(j,n+i,val);
		}
		sort(pic+1,pic+len+1,cmp);
		for(int j=1;j<=len;j++){
			if(cnt==i+n-1) break;
			int px=pic[j].l,py=pic[j].r,pv=pic[j].v;
			int tepx=find(px);
			int tepy=find(py);
			if(tepx!=tepy){
				fa[tepx]=tepy;
				ret+=pv;
				cnt++;
			}
		}
		mx=min(mx,ret);
	}
	printf("%lld",mx);
	return 0;
}

