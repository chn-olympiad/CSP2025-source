#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],p=1;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1]) p++;
	}
	if(((p-1)/n+1)%2==1) cout<<(p-1)/n+1<<" "<<(p-1)%n+1;
	else cout<<(p-1)/n+1<<" "<<n-((p-1)%n);
	return 0;
} 
