#include<bits/stdc++.h>
using namespace std;
int n,a[1000010][3],f[1000010][3],c[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
		{
			for(int k=1;k<=3;k++)
			{
				f[i][1]=max(f[i-1][k]+a[i][1],f[i][1]);
				f[i][2]=max(f[i-1][k]+a[i][2],f[i][2]);
				f[i][3]=max(f[i-1][k]+a[i][3],f[i][3]);
			}
		}
		cout<<max(f[n][1],max(f[n][2],f[n][3]))<<endl;
    }
    return 0;
}
