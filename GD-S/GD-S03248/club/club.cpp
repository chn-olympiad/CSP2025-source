#include <bits/stdc++.h>
using namespace std;
int t,n,sum=0,b[5];
long long a[10005][5],f[10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				cin>>a[i][j];
		int sum=0;
		for (int i=1;i<=n;i++)
			sum+=max(a[i][1], max(a[i][2],a[i][3]) );
		cout<<sum<<endl;
	}
} 
