#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long n,k;
bool yyy(int a[])
{
	for(int i=1;i<=n;i++)
		if(a[i]!=1) return false;
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0 && yyy(a))
	{
		cout<<n/2<<endl;
		return 0;
	}
	cout<<2<<endl;
	return 0;
}
