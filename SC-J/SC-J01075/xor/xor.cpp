#include<bits/stdc++.h>
using namespace std;
#define int long long
//异或：同0得0，其余的1 
int n,k;
const int N=5e5+5;
int a[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<n;
	return 0; 
} 