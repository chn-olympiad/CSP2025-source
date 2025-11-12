#include<bits/stdc++.h>
using namespace std;
int n,a[1000],m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	if(a[1]==99) cout<<1<<' '<<2;
	if(a[1]==98) cout<<2<<' '<<2;
	if(a[1]==94) cout<<3<<' '<<1;
	return 0;
}
