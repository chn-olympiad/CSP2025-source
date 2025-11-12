#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main() 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum=0,n;
	cin>>n;
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a-1,a+3);
	if(sum>a[2]*2)
	{
		cout<<1;
	}
	else
	{
		cout<<0; 
	}
	return 0;
}
