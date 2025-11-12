#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[50001];
	bool flag=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
			flag=1;
	}
	if(flag==0&&k==0)
		cout<<a[1];
	fclose(stdin);
	fclose(stdout);
}
