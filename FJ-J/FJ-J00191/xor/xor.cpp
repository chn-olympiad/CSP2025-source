#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int s[101];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	cout<<n/2;
	fclose(stdin);fclose(stdout);
	return 0;
}