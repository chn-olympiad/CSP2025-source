#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
 	int s,k=1;
	int a[99999]={0};
	cin>>s;
	while(s>9)
	{
		a[k]=s%10;
		s/=10;
		k++;
	}
	a[k]=s%10;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j+1]>=a[j])
			{
				swap(a[j+1],a[j]);
			}
		}
	}
	for(int i=1;i<=k;i++)cout<<a[i];

	
	return 0;
}
 