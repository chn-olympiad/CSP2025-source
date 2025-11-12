#include <bits/stdc++.h>
using namespace std;
int a[5002],cot=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,f=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cot+=a[i];
	}
	if(cot>2*a[n])
	cout<<"1";
	else
	cout<<"0";
}