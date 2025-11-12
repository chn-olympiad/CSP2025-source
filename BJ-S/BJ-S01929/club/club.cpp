#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],b[N][3],hv[3],wh[N];
vector<int> v;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n;
    int ans;
    while(t--)
    {
        hv[0]=hv[1]=hv[2]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            b[i][0]=a[i][0],b[i][1]=a[i][1],b[i][2]=a[i][2];
            sort(b[i],b[i]+3);
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])hv[0]++,wh[i]=0,ans+=a[i][0];
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])hv[1]++,wh[i]=1,ans+=a[i][1];
            else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1])hv[2]++,wh[i]=2,ans+=a[i][2];
        }
        v.clear();
        for(int op=0;op<3;op++)
        {
            if(hv[op]>n/2)
            {
                for(int i=1;i<=n;i++)
                {
                    if(wh[i]==op)
                    {
                        v.push_back(b[i][2]-b[i][1]);
                    }
                }
                sort(v.begin(),v.end());
                for(int i=0;i<hv[op]-n/2;i++)ans-=v[i];
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
