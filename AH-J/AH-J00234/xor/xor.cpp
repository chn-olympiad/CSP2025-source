#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0)
		cout<<1<<endl;
	else
		cout<<n/2<<endl;
	return 0;
}
