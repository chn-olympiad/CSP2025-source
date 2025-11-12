#include<bits/stdc++.h>
using namespace std;
struct node
{
	int next,cur;
};
vector<node> ra[100000];
int n,m,k;
int main()
{
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
	    int u,v,w;
		cin>>u>>v>>w;
	    ra[u].push_back({v,w});
    	ra[v].push_back({u,w});	
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		bool f[10000];
		int a[n+1];
		if(c==0)
		{
			for(int i=1;i<=n;i++)
         	{
	        	for(int j=i;j<ra[i].size();j++)
	     	{
		        int cnt=ra[j][i].next;
     			if(cnt<ra[j][i].cur) ra[j][i].cur=cnt;
     			ra[n][m].next=a[j]+a[ra[j][i].next];
	     	}
      	}
		}
		 for(int j=1;j<=n;j++)
		{
			for(int it=0;it<=k;it++)
			{
				if(it<=ra[j].size())
				{
		    		int cnt=c+a[j]+a[ra[j][it].next];
		    		f[ra[j][it].next]=true;
 		    		if(cnt<ra[j][it].cur) ra[j][it].cur=cnt;
				}
			}
			for(int l=1;l<=n;l++)
			{
				if(f[ra[j][l].next]==false)
				{
					int cnt=c+a[j]+a[ra[j][l].next];
					ra[j].push_back({l,cnt});
				}
		   }
	    }
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<ra[i].size();j++)
		{
		    int cnt=ra[j][i].next;
			if(cnt<ra[j][i].cur) ra[j][i].cur=cnt;
		}
	}
	cout<<ra[n][m].next<<endl;
	return 0;
}