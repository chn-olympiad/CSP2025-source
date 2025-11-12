#include <bits/stdc++.h>
using namespace std;
int a[115];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n = 0,m = 0,R = 0,sum = 0,k = 0,cnt = 0,sum2 = 0;
	cin>>n>>m;
	for(int i = 0;i<n*m;i++)
	{
		cin>>a[i];
	}
	R = a[0];
	sort(a+0,a+n*m,cmp);
	for(int i = 0;i<n*m;i++)
	{
		if(a[i] == R)
		{
			sum = i+1;
		}
	}
	k = sum/n;
	if(sum%n != 0)
	{
		k+=1;
		cout<<k<<" "<<m;
	}
	else
	{
		cout<<k<<" "<<m;
	}
	return 0;
}
