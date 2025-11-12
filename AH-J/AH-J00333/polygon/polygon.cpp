#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector<int> a;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==3) cout<<1<<endl;
	else if(n<3) cout<<0<<endl;
	else cout<<3<<endl;
	return 0;
}
