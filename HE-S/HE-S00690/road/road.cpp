#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][5];
int b[10005];
int ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(n--){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
	}
	for(int i=1;i<=n;i++) b[i]=a[i][3];
	sort(b+1,b+n+1);
	for(int i=1;i<n;i++) ans+=b[i];
	cout<<ans;
	return 0;
}
