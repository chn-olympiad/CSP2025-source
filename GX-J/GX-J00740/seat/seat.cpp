#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
bool flag;
int n,m,a[110],num=1,s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++)
		cin>>a[i];
	int r=a[1];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(a[i]==r)	{r=i;break;}
	if(r==1) {cout<<"1 1"; return 0;}
	flag=1;
	for(int i=1;i<=n;)
		for(int j=1;j<=m;)
		{
			if(i==n || (i==1 && j!=1))	{j++;flag=0;}
			if(j%2!=0 && flag==1) i++;
			if(j%2==0 && flag==1) i--;
			num++;
			if(num==r)	{cout<<j<<" "<<i;return 0;}
			flag=1;
		}
	return 0;
}
