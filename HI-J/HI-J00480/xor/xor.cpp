#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans,n,maxx;
int main(){
    freopen("xor.in","r",stdin);	
    freopen("xor.out","w",stdout);		
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1) ans++;
		maxx=max(i,maxx);
	} 
	cout<<ans;

	return 0;
}
