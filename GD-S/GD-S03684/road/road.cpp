#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i=62,a=1;
	for(;i>0;i--)
	{
		a*=i;
		a%=998244353;
	}
	
	cout<<a<<endl;
	return 0;
}
