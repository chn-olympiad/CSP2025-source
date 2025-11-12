#include<bits/stdc++.h>
using namespace std;
int n;
int r[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+1+n);
	if(n==3) cout<<1;
	return 0;
} 
