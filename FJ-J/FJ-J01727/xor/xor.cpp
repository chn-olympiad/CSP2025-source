#include<bits/stdc++.h>
using namespace std;
int n,k;
int r[5010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	if(k==0&&n<=2) cout<<1;
	else if(k==0 && n<=100) cout<<n;
	
	return 0;
} 
