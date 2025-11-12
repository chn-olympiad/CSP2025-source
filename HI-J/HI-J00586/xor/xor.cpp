#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[110000],ans=0;
	cin>>n>>k;
	long long i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		 ans++;
	}
	cout<<ans;
	return 0;
}
