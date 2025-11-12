#include<iostream>
#include<algorithm>
using namespace std;
int t,n;
const int nr=1e5+10;
int a[nr][4],cnt[4],b[nr],c[nr],cur;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int j=1;j<=3;j++)cnt[j]=0;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)cin>>a[i][j];
            int maxid=0;
            for(int j=1;j<=3;j++)if(maxid==0||a[i][j]>a[i][maxid])maxid=j;
            cnt[maxid]++,sum+=a[i][maxid],b[i]=maxid;
        }
        for(int j=1;j<=3;j++)
            if(cnt[j]>n/2)
            {
                cur=0;
                for(int i=1;i<=n;i++)
                    if(b[i]==j)
                    {
                        int minn=2e9;
                        for(int k=1;k<=3;k++)
                            if(k!=j)minn=min(minn,a[i][j]-a[i][k]);
                        c[++cur]=minn;
                    }
                sort(c+1,c+cur+1);
                int ncnt=cnt[j]-n/2;
                for(int i=1;i<=ncnt;i++)sum-=c[i];
            }
        cout<<sum<<'\n';
    }
    return 0;
}
