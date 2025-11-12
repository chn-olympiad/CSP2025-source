#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const int M=2e4+5;
const ll inf=1e17+5;
int in(){
	char c=getchar();
	int k=0;
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}return k;
}
struct edge{
	int u,v;
	ll w;
}es[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int n,m,k,c[20],cnt,f[20],op[M];
ll ans=inf;
int find(int x){
	if(op[x]==x)return x;
	else return op[x]=find(op[x]);
}
bool add(int x,int y){
	int u=find(x),v=find(y);
	if(u==v)return 0;
	else{
		op[u]=v;
		return 1;
	}
}
void check(int x,ll ans2){
	ll sum=0,ans1=0;
	for(int i=1;i<=cnt;i++){
		edge d=es[i];
		if(d.u>n&&!f[d.u-n])continue;
		if(d.v>n&&!f[d.v-n])continue;
		if(add(d.u,d.v)){
			ans1+=d.w;
			sum++;
			if(sum==n+x-1){
				if(x==0)cnt=i;
				ans=min(ans,ans1+ans2);
				return ;
			}if(ans1+ans2>=ans)return ;
		}
		else if(x==0)es[i].w=inf;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("a.txt","r",stdin);
//	freopen("b.txt","w",stdout);
	n=in();m=in();k=in();
	for(int i=1;i<=m;i++){
		int u=in(),v=in(),w=in();
		es[++cnt]={u,v,w};
	}sort(es+1,es+1+cnt,cmp);
	for(int j=1;j<=n;j++)op[j]=j;
	check(0,0);
	for(int i=1;i<=k;i++){
		c[i]=in();
		for(int j=1;j<=n;j++){
			int x=in();
			es[++cnt]={n+i,j,x};
		}
	}sort(es+1,es+1+cnt,cmp);
	cnt=n-1+k*n;
	for(int i=1;i<(1<<k);i++){
		int x=0;ll val=0;
		for(int j=0;j<k;j++){
			f[j+1]=((i>>j)&1);
			if(f[j+1])x++,val+=c[j+1];
		}for(int j=1;j<=n+k;j++)op[j]=j;
		check(x,val);
	}cout<<ans;
	return 0;
} 
