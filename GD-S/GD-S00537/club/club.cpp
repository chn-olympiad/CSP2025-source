#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N=100005;

int n,p[N];
long long a[N][3],sum;

priority_queue<long long> q[3];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int t; cin>>t;
	
	for(;t;t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				if(a[i][p[i]]<a[i][j]) p[i]=j;
			}
			
			sum+=a[i][p[i]];
			
			long long res=-0x3f3f3f3f3f3f3f3f;
			for(int j=0;j<3;j++)
			{
				if(j==p[i]) continue;
				res=max(res,a[i][j]-a[i][p[i]]);
			}
			
			q[p[i]].push(res);
		}
		
		for(int i=0;i<3;i++)
		{
			while(q[i].size()>n/2) sum+=q[i].top(),q[i].pop();
		}
		
		cout<<sum<<"\n";
		
		sum=0;
		memset(p,0,sizeof(p));
		memset(a,0,sizeof(a));
		for(int i=0;i<3;i++) while(!q[i].empty()) q[i].pop();
	}
	
	
	return 0;
}
 
