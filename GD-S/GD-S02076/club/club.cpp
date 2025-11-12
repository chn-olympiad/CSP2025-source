#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int t;
int n;
int a[N][4];
int c[N];
int k[N];
int q[N];
int x,y,z;
int sum=0;
int o=1;
int maxn;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		memset(q,0,sizeof q);
		memset(c,0,sizeof c);
		memset(k,0,sizeof k);
		o=1;
		sum=0;
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			maxn=max(a[i][0],max(a[i][1],a[i][2]));
			if(maxn==a[i][0])c[i]=0;
			else if(maxn==a[i][1])c[i]=1;
			else c[i]=2;
			sum+=a[i][c[i]];
			k[c[i]]++;
		}
		x=max(k[0],max(k[1],k[2]));
		
		if(x==k[0])x=0;
		else if(x==k[1])x=1;
		else x=2;
		
		y=(x?0:1);
		z=(x==2?1:2);
		
		for(int i=1;i<=n;i++)
		{
			if(c[i]==x)
			{
				q[o]=max(a[i][y],a[i][z])-a[i][x];
				o++;
			}
		}
		int u=1;
		while(k[x]>n/2)
		{
			sum+=q[u];
			q[u]=0;
			u++;
			k[x]--; 
		}
		cout<<sum<<'\n';
	}
	return 0;
}

