#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,k,u,v,w;
struct node
{
	signed s,e;
	int w;
};	
node aa[signed(2e6+1e4)];
int idx=0;
int a[signed(1e4+10)][signed(1e4+10)];
signed jilu[signed(1e4+10)][signed(1e4+10)];
int xiu[15][signed(1e4+10)];
int c[15];
int fa[signed(1e4+10)];
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
int xuan=0;
int kru(int x,int y)
{
	int getx=get(x);
	int gety=get(y);
	if(getx==gety) return 0;
	else
	{
		fa[x]=gety;
		xuan++;
		return 1;
	}
}
bool cmp(node a,node b)
{
	return a.w == b.w ?a.s<b.s:a.w<b.w; 
}
signed main()
{
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		    a[i][j]=a[j][i]=1e17;
		}
	}
    for(int i=1;i<=m;i++)
    {
    	cin>>u>>v>>w;
    	a[v][u]=w;
    	a[u][v]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>xiu[i][j];
		}
	}
    
	int ans=1e16,anss=1e17;
	for(int i=0;i<=(1<<k)-1;i++)
	{
		ans=0;
		idx=0;
		xuan=0;
		for(int k=0;k<=n;k++) fa[k]=k;
    	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]!=1e17){
					aa[++idx].s=i,aa[idx].e=j,aa[idx].w=a[i][j];
					jilu[i][j]=idx-1,jilu[j][i]=idx-1;
				}	
			}
		}
		int now=i,cnt=1;
		
		while(now) {    
			if(now&1){
				ans+=c[cnt];
				for(int j=1;j<=n;j++)
				{
					if(j==cnt) continue;
					aa[++idx].s=cnt,aa[idx].e=j,aa[idx].w=xiu[cnt][j];
//					if(xiu[cnt][j] < aa[jilu[cnt][j]].w) aa[jilu[cnt][j]].w=xiu[cnt][j];
				}
			} 
			cnt++;
			now>>=1;
		}
		
		sort(aa+1,aa+idx+1,cmp);
		
		
//		cout<<"bian"<<endl;
//		for(int p=1;p<=idx;p++)
//		{
//			cout<<p<<" "<<aa[p].e<<" "<<aa[p].s<<" "<<aa[p].w<<endl;
//		}
//		
		xuan=0;
		for(int j=1;j<=idx || xuan==n-1;j++)
		{
			int qwert=kru(aa[j].s,aa[j].e);
			if(qwert==1)
			{
//				cout<<"jia "<<j<<endl;
				ans+=aa[j].w;
				xuan++;
			}
		}
		
		
		anss=min(ans,anss);
		
		for(int k=0;k<=n;k++) fa[k]=k;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				jilu[i][j]=jilu[j][i]=0;
			}
		}
		
		
//		cout<<i<<" "<<anss<<endl;
	}
	cout<<anss<<endl;
	return 0;
}
