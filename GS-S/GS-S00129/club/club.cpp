#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int MAXN = 1e5+5;
int t,n;
long long a[101][101][101];
int x[MAXN],y[MAXN],z[MAXN];
int zong[MAXN*3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        if(n<=200)
        {
            for(int i = 1;i<=n;i++)
            {
                cin>>x[i]>>y[i]>>z[i];
                int p = min(n/2+1,i);
                for(int j1 = 0;j1<p;j1++)
                {
                    int pp = min(n/2,i-j1-1);
                    for(int j2 = 0;j2<=pp;j2++)
                    {
                        int j3 = i-j1-j2-1;
                        if(j3>n/2)continue;
                        if(j1<n/2)a[j1+1][j2][j3] = max(a[j1+1][j2][j3],a[j1][j2][j3]+x[i]);
                        if(j2<n/2)a[j1][j2+1][j3] = max(a[j1][j2+1][j3],a[j1][j2][j3]+y[i]);
                        if(j3<n/2)a[j1][j2][j3+1] = max(a[j1][j2][j3+1],a[j1][j2][j3]+z[i]);
                    }
                }
            }
            long long maxn = -1;
            for(int i = 0;i<=n/2;i++)
            {
                for(int j = 0;j<=n/2;j++)
                {
                    int k = n-i-j;
                    if(k>n/2)continue;
                    maxn = max(maxn,a[i][j][k]);
                }
            }
            cout<<maxn<<"\n";
        }
        else
        {
        	int m1 = 0,m2 = 0,m3 = 0;
        	for(int i = 1;i<=n;i++)
        	{
        		cin>>x[i]>>y[i]>>z[i];
        		zong[i*3-2] = x[i];
        		zong[i*3-1] = y[i];
        		zong[i*3] = z[i];
        		m1 = max(m1,x[i]);
        		m2 = max(m2,y[i]);
        		m3 = max(m3,z[i]);
			}
			if(m2==0&&m3==0)
			{
				sort(x+1,x+n+1);
				long long ans = 0;
				for(int i = n;i>=n-n/2+1;i--)
				{
					ans+=x[i];
				}
				cout<<ans<<"\n";
			}
			else
			{
				long long ans = 0;
				sort(zong+1,zong+3*n+1);
				for(int i = 3*n;i>=n*2+1;i--)
				{
					ans+=zong[i];
				}
				cout<<ans<<"\n";
			}
		}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

