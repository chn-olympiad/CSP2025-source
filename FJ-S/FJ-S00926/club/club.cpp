#include<bits/stdc++.h>
using namespace std;
int a[100000+10][5];
int n;
int t1,t2,t3;
int ans;
int maxx;
int f(int x)
{
	if(t1>=n/2)
	{
		a[x][1]=0;
	}
	else if(t2>=n/2)
	{
		a[x][2]=0;
	}
	else if(t3>=n/2)
	{
		a[x][3]=0;
	}
	maxx=max(a[x][1],max(a[x][3],a[x][2]));
	if(maxx==a[x][1])
	{
		t1++;
	}
	if(maxx==a[x][3])
	{
		t3++;
	}
	if(maxx==a[x][2])
	{
		t2++;
	}
	if(x==1)
	{
		return maxx;
	}
	else
	{
		return ans=max(a[x][1],max(a[x][3],a[x][2]))+f(x-1);
	}
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0,t1=0,t2=0,t3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<f(n)<<endl;
	}
	return 0;
}

