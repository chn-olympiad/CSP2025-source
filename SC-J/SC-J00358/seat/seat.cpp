#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+10];
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ans=a[1],vis=0;
	for(int i=2;i<=n*m;i++)
	{
		if(ans<a[i]) vis++;
	}
	if(vis==0) cout<<1<<" "<<1;
	else if(n==m and vis==n) cout<<n<<" "<<m;
	else if(vis>=n) cout<<vis/n+1<<" "<<(vis+1)%m;
	else cout<<1<<" "<<vis+1;
	return 0;
}