#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000],f=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			f=1;
	}
	if(f==0)
	{
		cout<<n;
	}
}
