#include <bits/stdc++.h>
using namespace std;
int minv[10][100010];
int k[10];
int top[10];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=3;i++)
        {
        k[i]=0;
        top[i]=1;
        for(int j=1;j<=n;j++)
        minv[i][j]=100000000;
        }
        int x,y,z;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            int maxv=max(x,max(y,z));
            //cout<<maxv<<endl;
            ans+=maxv;
            if(maxv==x)
            {
                k[1]++;
                minv[1][top[1]+1]=min(maxv-y,maxv-z);
                top[1]++;
                sort(minv[1]+1,minv[1]+top[1]);
            }
            else if(maxv==y)
            {
                k[2]++;
                minv[2][top[2]+1]=min(maxv-x,maxv-z);
                top[2]++;
                sort(minv[2]+1,minv[2]+top[2]);
            }
            else if(maxv==z)
            {
                k[3]++;
                 minv[3][top[3]+1]=min(maxv-y,maxv-x);
                 top[3]++;
                sort(minv[3]+1,minv[3]+top[3]);
            }
            for(int j=1;j<=3;j++)
            {
            if(k[j]>n/2)
            {
                k[j]--;
                ans-=minv[j][1];
                for(int q=1;q<top[j];q++)
                    minv[j][q]=minv[j][q+1];
                top[j]--;
                break;
            }
            }
        }
        cout<<ans<<endl;
        }
    return 0;
}
