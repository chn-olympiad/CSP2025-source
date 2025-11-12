#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],num=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
			num++;
	}
	if(k==0)
	{
		for(int i=0;i<n-1;i++)
			if(a[i+1]==a[i]&&a[i]!=0)
			{
				num++;
				i++;
			}
		cout<<num;
	}
	if(k==1)
		cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
