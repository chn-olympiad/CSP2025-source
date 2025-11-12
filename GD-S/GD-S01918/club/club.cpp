#include <bits/stdc++.h>
using namespace std;
const int N=100010;
struct Club
{
	int a1,a2,a3,z; 
}a[N];
int n,c[4][N],l[4],g=0,t=0;
long long ans=0;
bool cmp(int x,int y)
{
	return a[x].z<a[y].z;
}
int main()
{
	ifstream cin("club.in");
	ofstream cout("club.out");
	cin>>t;
	while(t--)
	{
		l[1]=l[2]=l[3]=0;
		g=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)
			{
				l[1]++;
				c[1][l[1]]=i;
				a[i].z=a[i].a1-max(a[i].a2,a[i].a3);
				ans+=a[i].a1;
				if(l[1]>n/2)
				{
					g=1;
				}
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)
			{
				l[2]++;
				c[2][l[2]]=i;
				a[i].z=a[i].a2-max(a[i].a1,a[i].a3);
				ans+=a[i].a2;
				if(l[2]>n/2)
				{
					g=2;
				}
			}
			else if(a[i].a3>=a[i].a2&&a[i].a3>=a[i].a1)
			{
				l[3]++;
				c[3][l[3]]=i;
				a[i].z=a[i].a3-max(a[i].a2,a[i].a1);
				ans+=a[i].a3;
				if(l[3]>n/2)
				{
					g=3;
				}
			}
		}
		if(g==0)
		{
			cout<<ans<<endl;
		}
		else
		{
			sort(c[g]+1,c[g]+1+l[g],cmp);
			for(int i=1;l[g]>n/2;i++)
			{
				l[g]--;
				ans-=a[c[g][i]].z;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
 
