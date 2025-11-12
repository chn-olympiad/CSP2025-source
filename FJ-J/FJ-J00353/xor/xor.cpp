#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long sum;
long long temp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		sum+=temp;
	}
	if(sum<0)
	{
		sum = sum*-1;
	}
	cout<<sum%998331;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
