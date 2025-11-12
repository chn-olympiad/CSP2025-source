#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5];
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
if(n<3)
{
	cout<<0;
}
else
{
	if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)
	cout<<1;
	else
	{
		cout<<0;
	}
}
}
