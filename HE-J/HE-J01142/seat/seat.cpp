#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105]={};
int n,m;
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{
	cin>>a[i];
}
int t=a[1],t2=n*m,t3;
sort(a+1,a+t2+1,cmp);
for(int i=1;i<=t2;i++)
{
	if(a[i]==t)
	{
		t3=i;
		break;
	}
}
int i=1,j=1;
t3--;
while(t3--)
{
	
	if(i<n&&j%2==1)
	{
		i++;
	}
	else if(i>=n&&j%2==1)
	{
		j++;
	}
	else if(i>1&&j%2==0)
	{
		i--;
	}
	else
	{
		j++;
	}
}
cout<<j<<' '<<i;
}

