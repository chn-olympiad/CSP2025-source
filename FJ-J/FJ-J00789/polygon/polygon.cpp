#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
int main()
{
	//ое©чак                    
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3) cout<<0;
	if(n==3)
	{
		if(a[1]+a[2]+a[3] > max( max(a[1],a[2]) , a[3] ) ) 
			cout<<1; 
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
