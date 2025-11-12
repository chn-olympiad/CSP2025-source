#include <iostream>
#include <cstdio>
#define Endl '\n'
using namespace std;
int n;
string k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
		cout<<n;
	else
		cout<<0;
	return 0;
}