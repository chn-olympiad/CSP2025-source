#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1][5];
        vector<int>cnt[4];
        for(int i=1;i<=n;i++)
        scanf("\n%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                int l1=(j%3)+1;
                int l2=((j+1)%3)+1;
                if(a[i][j]>=a[i][l1]&&a[i][j]>=a[i][l2])
                {
                    ans+=a[i][j];
                    cnt[j].push_back(i);
                    a[i][4]=a[i][j]-max(a[i][l1],a[i][l2]);
                    break;
                }
            }
        }
        for(int j=1;j<=3;j++)
        {
            if(cnt[j].size()>n/2)
            {
                priority_queue<int,vector<int>,greater<int> >q;
                for(int i=0;i<cnt[j].size();i++)
                    q.push(a[cnt[j][i]][4]);
                for(int i=1;i<=cnt[j].size()-n/2;i++)
                {
                    ans-=q.top();
                    q.pop();
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
