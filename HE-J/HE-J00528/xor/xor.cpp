#include<bits/stdc++.h>
using namespace std;
int a[500005],b;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b=a[i]/2;
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
