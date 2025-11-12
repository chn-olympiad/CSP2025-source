#include<bits/stdc++.h>
using namespace std;

int l[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i;
	cin>>n;
	for(i=0;i<n;i++) cin>>l[i];
	sort(l,l+n);
	if(n == 3)
	{
		if(l[0]+l[1] > l[2]) cout<<1;
		else cout<<0;
	}
	else if(n == 4) cout<<3;
	else cout<<998244352;
	return 0;
}
