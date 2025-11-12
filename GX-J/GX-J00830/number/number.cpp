#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long b;
	int a[1000001],s=0;
	cin>>b;
	while(b)
	{
		s++;
		a[s]=b%10;
		b/=10;
	}
	sort(a+1,a+s+1);
	for(int i=s;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
