#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int n;
int a[N];
int sum;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	int ma=a[n];
	if(sum/2>ma) cout<<1;
	else cout<<0;
	return 0;
} 
