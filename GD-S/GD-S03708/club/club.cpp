#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;
int T;
int a[N][5];
int num[5];

struct node
{
	int a,b,c;
}b[N];

bool cmp(node a,node b)
{
	return a.b<b.b;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	
	while(T--)
	{
		int n,sum=0,m=0;cin>>n;
		num[0]=num[1]=num[2]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			sum+=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])
				++num[0],a[i][3]=0;
			else if(a[i][1]>a[i][2])
				++num[1],a[i][3]=1;
			else ++num[2],a[i][3]=2;
		}
		
		if(max(num[0],max(num[1],num[2]))<=n/2)
			cout<<sum<<'\n';
		else
		{
			int mx,cnt;
			if(num[0]>num[1]&&num[0]>num[2]) mx=0,cnt=num[0];
			else if(num[1]>num[2]) mx=1,cnt=num[1];
			else mx=2,cnt=num[2];
			
			for(int i=1;i<=n;i++)
			{
				if(a[i][3]==mx)
				{
					int t,id;
					if(mx==0)
					{
						if(a[i][1]>a[i][2]) t=a[i][1],id=1;
						else t=a[i][2],id=2;
					}
					if(mx==1)
					{
						if(a[i][0]>a[i][2]) t=a[i][0],id=0;
						else t=a[i][2],id=2;
					}
					if(mx==2)
					{
						if(a[i][0]>a[i][1]) t=a[i][0],id=0;
						else t=a[i][1],id=1;
					}
					b[++m].a=id;
					b[m].b=a[i][mx]-t;
					b[m].c=a[i][mx]-(a[i][0]+a[i][1]+a[i][2]-a[i][mx]-t);
				}
			}
			
			sort(b+1,b+m+1,cmp);
			for(int i=1;i<=cnt-n/2;i++)
			{
				if(num[b[i].a]==n/2)
				{
					if(mx==0)
					{
						if(b[i].a==1) ++num[2],sum-=b[i].c;
						else ++num[1],sum-=b[i].c;
					}
					else if(mx==1)
					{
						if(b[i].a==0) ++num[0],sum-=b[i].c;
						else ++num[2],sum-=b[i].c;
					}
					else
					{
						if(b[i].a==0) ++num[0],sum-=b[i].c;
						else ++num[1],sum-=b[i].c;
					}
				}
				else
					++num[b[i].a],sum-=b[i].b;
			}
			
			cout<<sum<<'\n';
		}	
	}
	
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
