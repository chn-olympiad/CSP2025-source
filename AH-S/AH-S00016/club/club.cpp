#include<bits/stdc++.h>
using namespace std;
struct S{
	int sa1,sa2,sa3;
}b[100005];
bool cmp1(S x,S y)
{
	return x.sa1>y.sa1;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==2)
		{
			int a[3][4];
	for(int i=1;i<=2;i++)
    {
		for(int j=1;j<=3;j++)
		    cin>>a[i][j];
	}
	int maxx=0;
	maxx=max(a[1][1]+a[2][2],maxx);
	maxx=max(a[1][1]+a[2][3],maxx);
	maxx=max(a[1][2]+a[2][1],maxx);
	maxx=max(a[1][2]+a[2][3],maxx);
	maxx=max(a[1][3]+a[2][1],maxx);
	maxx=max(a[1][3]+a[2][2],maxx);
	cout<<maxx<<endl;
		}
		else
		{
			bool f1=true;
			for(int i=1;i<=n;i++)
			{
				cin>>b[i].sa1>>b[i].sa2>>b[i].sa3;
				if(b[i].sa2!=0||b[i].sa3!=0)f1=false;
			}
			if(f1==true)
			{
				sort(b+1,b+1+n,cmp1);
	long long sum=0;
	for(int i=1;i<=n/2;i++)
	{
		sum+=b[i].sa1;
	}
	cout<<sum<<endl;
			}
		}
	}
	return 0;
}
