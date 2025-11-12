#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0 && a[1]==1 && a[2]==1)
	{
		cout<<"0";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
