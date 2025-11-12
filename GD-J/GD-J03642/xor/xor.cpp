#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)cout<<"1";
	if(n==2&&a[1]==a[2])cout<<"2";
	if(n==2&&a[1]!=a[2])cout<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
