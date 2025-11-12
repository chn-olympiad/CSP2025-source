#include <bits/stdc++.h>
#include <fstream>
using namespace std;
long long t,n;
struct Node
{
	long long a,b,c,id,site=0;
}m[100005];
long long num[4],ans=-1,vis[100005];
void dfs(long long k,long long sum)
{
	if(num[1]+num[2]+num[3]==n)
	{
		ans=max(ans,sum);
	}
	else
	{
		m[k].site=1;
		vis[m[k].id]=1;
		num[1]++,sum+=m[k].a;
		if(num[1]<=n/2)
		{
			dfs(k+1,sum);
		}
		num[1]--,sum-=m[k].a;
		num[2]++,sum+=m[k].b;
		m[k].site=2;
		if(num[2]<=n/2)
		{
			dfs(k+1,sum);
		}
		num[2]--,sum-=m[k].b;
		num[3]++,sum+=m[k].c;
		m[k].site=3;
		if(num[3]<=n/2)
		{
			dfs(k+1,sum);
		}
		num[3]--,sum-=m[k].c;
	}
}
int main()
{
	ifstream fin("club.in");
	ofstream fout("club.out");
	fin>>t;
	for(int j=1;j<=t;j++){
		fin>>n;
		for (int i=1;i<=n;i++)
		{
			m[i].id=i;
			fin>>m[i].a>>m[i].b>>m[i].c;
		}
		dfs(1,0);
		fout<<ans<<endl;
		ans=-1;
	}
	fin.close();
	fout.close();
}
