#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+7;
int in(){
	int x=0;
	int f=1;
	char c;
	c=getchar();
	while(c!='-'&&(!(c>='0'&&c<='9'))) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
	return x;
}
int n,m,k,A;
struct node{
	int u,v,w;
}edge[N],edgem[N];
int c[20],a[12][N];
int f[N],used[10];
ll ans3;
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(node &x,node &y){
	return x.w<y.w;
}
void solve1(){
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(fu!=fv){
			f[fu]=fv;
			cnt++;
			ans+=edge[i].w;
		}
		if(cnt==n-1) break;
	}
	printf("%lld\n",ans);
}
void solve2(){
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k;j++){
			if(a[j][i]==0){
				f[find(n+j)]=f[find(i)];
			}else{
				edge[++m].u=n+j;
				edge[m].v=i;
				edge[m].w=a[j][i];	
			}
		}
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(fu!=fv){
			f[fu]=fv;
			cnt++;
			ans+=edge[i].w;
		}
		if(cnt==n-1) break;
	}
	printf("%lld\n",ans);
}
void dfs(int x){
	if(x>k){
		ll ans0=0;
		int mcnt=m,cnt=0;
		for(int i=1;i<=m;i++){
			edgem[i]=edge[i];
		}
		for(int j=1;j<=k;j++){
			if(used[j]){
				ans0+=c[j];
				for(int i=1;i<=n;i++){
					edgem[++mcnt].u=n+j;edgem[mcnt].v=i;edgem[mcnt].w=a[j][i];
				}
			}
		}
		
		for(int i=1;i<=n+k;i++) f[i]=i;
		sort(edgem+1,edgem+mcnt+1,cmp);
		for(int i=1;i<=mcnt;i++){
			int fu=find(edgem[i].u),fv=find(edgem[i].v);
			if(fu!=fv){
				f[fu]=fv;
				cnt++;
				ans0+=edgem[i].w;
			}
			if(cnt==n+k-1) break;
		}
		if(ans3==-1) ans3=ans0;
		else ans3=min(ans3,ans0);
		
		return;
	}
	used[x]=0;
	dfs(x+1);
	used[x]=1;
	dfs(x+1);
}
void solve3(){
	ans3=-1;
	dfs(1);
	printf("%lld\n",ans3);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	A=1;
	n=in();
	m=in();
	k=in();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=in();
		v=in();
		w=in();
		edge[i].u=u,edge[i].v=v,edge[i].w=w;
	}
	for(int i=1;i<=k;i++){
		c[i]=in();
		if(c[i]!=0) A=0;
		int p=0;
		for(int j=1;j<=n;j++) {
			a[i][j]=in();
			if(a[i][j]==0) p=1;
		}
		if(p==0) A=0;
	}
	if(k==0) solve1();
	else if(A==1) solve2();
	else if(k<=5) solve3();
	else solve3();
	return 0;
}