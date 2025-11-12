#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i+=2)
		ans=ans+n-i;
	cout<<ans;
	return 0;
}