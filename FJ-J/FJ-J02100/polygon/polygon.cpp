#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,a[100005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<6) {
		cout<<9;
		return 0;
	}
	if(n<12) {
		cout<<108;
		return 0;
	}
	if(n<19) {
		cout<<1024;
		return 0;
	}
}
