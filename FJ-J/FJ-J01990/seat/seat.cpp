#include<bits/stdc++.h>
using namespace std;
int n,m,z;
int f[400]={};
bool p(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>f[i];
	int r=f[1];
	sort(f+1,f+1+n*m,p);
	for(int i=1;i<=n*m;i++)
	{
		if(f[i]==r)
		{
			z=i;
			break;
		}
	}
	int y=(z+m-1)/m;
	int x=z-(y-1)*m;
	if(y%2==0)x=m-x+1;
	cout<<y<<' '<<x<<endl;
	return 0;
}

