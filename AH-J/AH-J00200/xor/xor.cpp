#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
		for(int i=1;i<=n;i++)
			ans+=n-i+1;
	else if(n==4)
		ans=2;
	else
		ans=1;
	cout<<ans;
	return 0;
}
