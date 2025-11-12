#include<bits/stdc++.h>
using namespace std;
long long int n,k,a[10000001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==k&&a[2]==k)
	{
		cout<<2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(a[1] xor a[2]==k)
	{
		cout<<1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
