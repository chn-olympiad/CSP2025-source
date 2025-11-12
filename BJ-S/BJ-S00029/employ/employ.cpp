#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=n-1;i>1;i--)
	{
		n*=i;
		n%=998;
		n%=244;
		n%=353;
	}
	cout<<n;
	return 0;
}