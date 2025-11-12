#include<bits/stdc++.h>
using namespace std;
int t,n,a[100050][4],f[4][100050],ans;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        cin>>n;
        int nn=n/2;
        int b[7]={0};
        for(int i=1;i<=n;i++)
        {
            int temp=0;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        int aa[4]={0,0,0,0};
        for(int i=1;i<=n;i++)
        {
            int temp=0;
            int m=1;
            for(int j=1;j<=3;j++)
            {
                if(temp<a[i][j]&&aa[j]<nn)
                {
                	temp=a[i][j];
                	m=j;
				}
            }
            for(int j=1;j<=3;j++)
            {
                if(m==j)
                {
                	aa[m]++;
                	f[m][i]=f[m][i-1]+temp; 
				}
				else
				{
					f[j][i]=f[j][i-1]; 
				}
            }
            //cout<<i<<' '<<f[i]<<'\n';
        }
        for(int i=1;i<=3;i++)
        {
            ans+=f[i][n];
        }
        cout<<ans<<'\n';
    }

    return 0;
}
//三个部门单独枚举会漏啊？？
//6:18 准备爆0离场了 
//能省3吗    。。。。 
//希望数据水一点； 
