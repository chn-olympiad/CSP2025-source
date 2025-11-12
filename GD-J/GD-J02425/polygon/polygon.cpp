#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n; 
	int ans=0;
	for(int i=3;i<=n;i++)
	{
		ans+=n/i;
	}
	cout << ans;
}//À´Æ­ 
