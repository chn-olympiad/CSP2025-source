#include<bits/stdc++.h>
using namespace std;
long long int l,k,t=0;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>l>>k;
	for(int i=1;i<=l;i++)
	{
		cin>>a[i];	
	} 
	for(int i=1;i<l;i++)
	{
		int he=a[i];
		for(int j=i+1;j<=l+1;j++)
		{
			if(he==k)
			{
				t++;
				he=a[j];
				i=j;
				continue;
			} 
			he=he^a[j];
		}
	}
	cout<<t;
	return 0;
}
