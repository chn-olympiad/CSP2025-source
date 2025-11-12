//GZ-S00043 遵义市新蒲新区天立学校 刘傲雪 
#include <bits/stdc++.h>
using namespace std;
int t,n;
const int maxn=1e4+5;
int a[maxn][maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=2;i<=n+1;i++)
		{
			int da,j=1;
			if(a[i-1][j]>a[i-1][j+1])
				da=a[i-1][j];
			else
				da=a[i-1][j+1];
			ans+=max(da,a[i-1][j+2]);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

