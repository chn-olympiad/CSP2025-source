#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0,sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n];
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++)
		if(a[i]==k)ans++;
	cout<<ans;
	return 0;
}
