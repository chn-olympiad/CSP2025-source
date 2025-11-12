#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin)
	freopen("xor.out","w",stdout)
	long long int temp=0,a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	cout<<temp;
	return 0;
}