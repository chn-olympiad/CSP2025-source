#include<bits/stdc++.h>
using namespace std;
long long n,k,x,a[1000000],l=1,r=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=a[i-1]^x;
	}
	while(r<=n)
	{
		long long o=a[r]^a[l-1];
		if(o==k){
			ans++;
			l=r+1;
			r=r+1;
		} 
		else r++;
	}
	cout<<ans;
	return 0;
}
