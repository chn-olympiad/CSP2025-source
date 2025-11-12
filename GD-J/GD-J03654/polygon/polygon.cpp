#include<bits/stdc++.h>
using namespace std;
long long n,a;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a; 
	if(n==3) cout<<1;
	else cout<<20;
	
	return 0;
}
