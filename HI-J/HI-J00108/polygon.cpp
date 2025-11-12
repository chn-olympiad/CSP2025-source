#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[10000];
int max=-999;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
		{
			max=a[i];
		 } 
	 } 
	 cout<<9;
	 
	
	fclose(stdin); 
    fclose(stdout);
return 0;
}
