#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,m,sum,x,z,ans,sun,sn;
struct node {
	int x,y;
}a[N];
struct c{
	int x,y,z;
}b[N];
bool cmp(node a,node b)
{
	return a.x>b.x;
}
bool cmb(c a,c b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int h=1;h<=t;h++){
		ans=sum=sun=sn=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++)
			{
				cin>>a[j].x;
			}
			sort (a+1,a+3+1,cmp);
			b[i].x=a[1].x;
			b[i].y=a[2].x;
			b[i].z=a[3].x;
		}
		if (n==2)
		{
			if (b[1].x+b[2].y>b[1].y+b[2].x)
			{
				cout<<b[1].x;
				continue;
			}
			else{
				cout<<b[1].y+b[2].x;
				continue;
			}
		}
		sort(b+1,b+n+1,cmb);
		for (int i=1;i<=n;i++)
		sum+=b[i].x;					
		cout<<sum<<endl;
	}
	return 0;
}
