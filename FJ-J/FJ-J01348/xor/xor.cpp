#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(k==0)
		{
			if(a[i]==0) sum++;
			else if(a[i]==1&&a[i+1]==1)
			{
				sum++;
				i++;
			}
		}
		else
			if(a[i]==1) sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
