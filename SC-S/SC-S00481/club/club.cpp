#include <bits/stdc++.h>
using namespace std;
int t,n;
const int N=1e5+9;
struct node{
	int x,y,z;
}a[N];

int b[10005];
int c[10005];
int d[10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for (int i=1;i<=n;i++)
		{
			b[i]=a[i].x;
			c[i]=a[i].y;
			d[i]=a[i].z;
			sort(b+1,b+n+1);
			sort(c+1,c+n+1);
			sort(d+1,d+n+1);
		}
		int sum1=0,sum2=0,sum3=0;
		for (int i=1;i<=n/2;i++)
		{
			sum1+=b[i];
			sum2+=c[i];
			sum3+=d[i];
		}
		int sum4=max(sum1,sum2);
		cout<<max(sum4,sum3)<<endl;
	}
	return 0;
}