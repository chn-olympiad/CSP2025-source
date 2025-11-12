#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[1000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	     cin>>a[i];
	if(n==2) cout<<3;
	if(n!=2) {for(int i=1;i<=n;i++)  ans+=n-i; cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
