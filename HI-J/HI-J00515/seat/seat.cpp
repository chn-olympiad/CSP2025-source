#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n = 0,m = 0;
	cin>>n>>m;
	cin>>a[1];
	for(int i = 2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+2,a+n+1,cmp);
	int s1 = 0,s2 = 0;
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			s1++;
		}
		else if(a[i]<a[1])
		{
			s2++;
		}
	}
	if(s1>=n&&(n*m-s2)>=m)
	{
		cout<<s1/n+1<<" "<<(n*m-s2)%m;
	}
	else 
	{
		cout<<s1<<" "<<n*m-s2;
	}
	return 0;
}

