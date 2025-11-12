#include<iostream>
using namespace std;
int n,q;
string s1[1005],s2[1005],t1[10000005],t2[10000005];
int main()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for (int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
	}
	return 0;
}
