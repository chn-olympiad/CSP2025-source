//GZ-S00030 绥阳县绥阳中学 余翔 
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;
using namespace std;
const int maxm=1e6+86;
const int maxn=1e5;
const int inf=1e9;
struct edge{
	int u,v,w;
	bool operator<(const edge &a)const{
	return a.w>w;
	}
}e[maxm*2];
int cnt;//边数 
int n,m,k;
bool choose[maxn];//最多选n-1条边 
long long ans1=0;

int f[maxn];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int c[11];
int d[maxn][11];
void uni(int x,int y){
    int fx=find(x);
    int fy=find(y);
	if(fy<fx)  swap(fx,fy);
	f[fy]=find(fx);
	f[y]=find(y);
	f[x]=find(x);
}
bool flag[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    f[i]=i;
    for(int i=1;i<=m;i++){
    	int x,y,w;
    	scanf("%d%d%d",&x,&y,&w);
    	e[++cnt].u=x;
    	e[cnt].v=y;
    	e[cnt].w=w;
	}
	for(int j=1;j<=k;j++){
		scanf("%d",&c[j]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&d[i][j]);
			e[++cnt].u=j+n;
			e[cnt].v=i;
			e[cnt].w=d[i][j];
		}
	}
	sort(e+1,e+1+cnt);
	/*for(int i=1;i<=cnt;i++)
	cout<<e[i].w<<endl;*/
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].u;
		int v=e[i].v;
		if(v<u) swap(u,v);
		if(find(u)!=find(v)) 
		{
		if(v>n) flag[v]=1;
		choose[i]=1; 
		ans1+=e[i].w;
		uni(u,v);	
		}
	}
	for(int i=1;i<=k;i++)
	if(flag[i]) ans1+=c[i];
	cout<<ans1;
    
	fclose(stdin);
	fclose(stdout);
	return 0;
}

