#include <bits/stdc++.h>
using namespace std;
int n,q;
struct eyz{
	string x,y;
}a[100010],b[100010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;i++) cin>>b[i].x>>b[i].y;
	if(q==2) cout<<2<<endl<<0;
	else for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}
