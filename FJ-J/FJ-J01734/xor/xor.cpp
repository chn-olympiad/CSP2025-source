#include<bits/stdc++.h>
using namespace std;
long long a[50010], n, k, s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(a[i]==1) s++;
	}
	if(k==1) cout<<s;
	else cout<<n-s;
	return 0;
}

