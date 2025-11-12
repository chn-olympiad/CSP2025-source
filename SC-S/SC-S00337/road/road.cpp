#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e6+100,M=12;

int n,m,k;
struct Edge{
    int u,v,w;
    bool sg;
}dt[N];
int f[N];
int tot;
int c[M],a[M][N];

int find(int x)
{
    if(x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

bool A=true;
Edge G[N],new_G[N];
int idx;

bool flag[12];

int calc()
{
	int n1=n,m1=n-1,ans=0;
	for(int i=1;i<=n-1;i++) new_G[i]=G[i];
	for(int i=1;i<=k;i++)
		if(flag[i])
		{
			ans+=c[i];
			for(int j=1;j<=n;j++)
				new_G[++m1]={j,i+n,a[i][j]};
		}
	for(int i=1;i<=n+k;i++) f[i]=i;
	sort(new_G+1,new_G+m1+1,[&](Edge x,Edge y){
        return x.w<y.w;
    });
	for(int i=1;i<=m1;i++)
    {
        int x=new_G[i].u,y=new_G[i].v;
        x=find(x),y=find(y);
        if(x==y) continue;
        f[x]=y,ans+=new_G[i].w;
    }	
    return ans;
}

void dfs(int p=1)
{
	if(p==k+1) return tot=min(tot,calc()),void();
	flag[p]=1;
	dfs(p+1);
	flag[p]=0;
	dfs(p+1);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&dt[i].u,&dt[i].v,&dt[i].w);
        
	sort(dt+1,dt+m+1,[&](Edge x,Edge y){
        return x.w<y.w;
    });
    
    for(int i=1;i<=k;i++)
    {
    	scanf("%lld",&c[i]);
    	if(c[i]!=0) A=false;
    	for(int j=1;j<=n;j++)
        	scanf("%lld",&a[i][j]); 
	}
        
    if(A)
    {
    	tot=0;
    	for(int i=1;i<=k;i++)
    		for(int j=1;j<=n;j++)
    			dt[++m]={j,i+n,a[i][j]};
	}
	
	sort(dt+1,dt+m+1,[&](Edge x,Edge y){
        return x.w<y.w;
    });
	for(int i=1;i<=n+k;i++)   f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=dt[i].u,y=dt[i].v;
        x=find(x),y=find(y);
        if(x==y) continue;
        f[x]=y,tot+=dt[i].w;
        if(!A) dt[i].sg=true;
    }
	if(k==0 || A) return cout<<tot<<endl,0;
	for(int i=1;i<=m;i++)
		if(dt[i].sg)
		G[++idx]=dt[i];
	dfs();
	cout<<tot<<endl;
	return 0;
}
