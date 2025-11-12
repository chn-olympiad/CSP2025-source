#include<bits/stdc++.h>
using namespace std;
int a[1005],n,k; 
int main()
{
	fropen("xor.in","r",stdin);
    fropen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=1)
	{
		cout<<; 
	} 
    else
	{
	   cout<<k;	
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
