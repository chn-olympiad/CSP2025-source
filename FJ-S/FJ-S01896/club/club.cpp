#include <bits/stdc++.h>

using namespace std;

struct sub{
	int a;
	int id;
	int p;
};

bool px(sub a,sub b)
{
	return a.a>b.a;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		int n,o=0;
		scanf("%d",&n);
		sub a[n][3],b[3][n];
		int c[3]={0},z=n/2;;
		for(int j=0;j<n;++j)
		{
			cin>>a[j][0].a>>a[j][1].a>>a[j][2].a;
			a[j][0].id=0,a[j][1].id=1,a[j][2].id=2;
		}
		for(int j=0;j<n;++j)
		{
			sort(a[j],a[j]+3,px);
		}
		for(int j=0;j<n;++j)
		{
			for(int k=2;k>=0;--k)
			{
				int x=c[a[j][0].id],y=a[j][0].id;
				if(x<=z)
				{
					b[y][x].a=a[j][0].a;
					b[y][x].id=j;
					++c[y];
					o+=a[j][0].a;
					break;
				}
				else
				{
					sub m;
					m.a=b[y][0].a;
					for(int i=1;i<x;++i)
					{
						if(b[y][i].a<m.a)
						{
							m.a=b[y][i].a;
							m.id=b[y][i].id;
						}
					}
				}
			}
		}
		cout<<o<<endl;
	}
	
	return 0;
}
