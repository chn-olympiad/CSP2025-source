#include<bits/stdc++.h>
using namespace std;
int n,a[50000],sum,maxx=0;
bool dis[50000];
vector<int>q;
int cnt=0;
void dfs(int u,int k,int o)
{
	if(k>=o)
	{
		sum=0;
		maxx=0;
		for(int i=0;i<k;i++)
		{
		//	cout<<q.at(i)<<" ";
			sum+=q.at(i);
			maxx=max(maxx,q.at(i));
		}
		
		//cout<<sum<<" "<<maxx<<" ";
		//int l=q.at(k);
		if(sum>2*maxx)cnt++;
	//	cout<<"\n";
	}
	else{
		for(int i=u;i<=n;i++)
		{
			if(dis[i]==0)
			{
				q.push_back(a[i]);
				dis[i]=1;
				dfs(i,k+1,o);
				dis[i]=0;
				q.pop_back(); 
			}
		}
	}
}
int  main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		dfs(1,0,i);
	}
	cout<<cnt;
	
	return 0;
}
/*


5
1 2 3 4 5
5
2 2 3 8 10
*/
