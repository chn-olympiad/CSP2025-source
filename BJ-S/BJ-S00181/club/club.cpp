#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,sum[3],c[100005];
vector<int> b[4];
struct dat{int x,id;} a[100005][4];
signed main()
{
    int i,j,k,mx=0,m,t=0;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (i=1;i<=3;i++)
        {
            b[i].clear();
            sum[i]=0;
        }
        for (i=1;i<=n;i++)
            for (j=1;j<=3;j++)
                a[i][j]={0,0};
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=3;j++)
            {
                cin>>a[i][j].x;
                a[i][j].id=j;
                sort(a[i]+1,a[i]+4,[](dat x,dat y){return x.x>y.x;});
            }
        }
        for (i=1;i<=n;i++)
            b[a[i][1].id].push_back(a[i][1].x);
        for (i=1;i<=3;i++)
        {
            for (int j:b[i])
                sum[i]+=j;
            if (b[i].size()>n/2)
            {
                m=b[i].size()-n/2;
                for (j=1;j<=n;j++)
                    c[j]=a[j][1].x-a[j][2].x;
                sort(c+1,c+n+1);
                for (j=1;j<=m;j++)
                    sum[i]-=c[j];
            }
        }
        cout<<sum[1]+sum[2]+sum[3]<<endl;
    }
    return 0;
}

