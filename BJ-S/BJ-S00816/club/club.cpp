#include<bits/stdc++.h>
using namespace std;
int cnt[4];
int a[100005][4],ty[100005];
int f[100005];
long long ans=0;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        ans=0;
        int n;
        cin>>n;
        cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
                cin>>a[i][j];
            int maxx=max(max(a[i][1],a[i][2]),a[i][3]);
            if(a[i][1]==maxx)
            {
                cnt[1]++;
                ans+=a[i][1];
                f[i]=maxx-max(a[i][2],a[i][3]);
                ty[i]=1;
            }
            else if(a[i][2]==maxx)
            {
                cnt[2]++;
                ans+=maxx;
                f[i]=maxx-max(a[i][1],a[i][3]);
                ty[i]=2;
            }
            else
            {
                cnt[3]++;
                ans+=maxx;
                f[i]=maxx-max(a[i][2],a[i][1]);
                ty[i]=3;
            }
        }
        for(int i=1;i<=3;i++)
        {
            if(cnt[i]>n/2)
            {
                int k=cnt[i]-n/2;
                for(int j=1;j<=n;j++)
                {
                    if(ty[j]==i)
                        q.push(f[j]);
                }
                while(k--)
                {
                    ans-=q.top();
                    q.pop();
                }
                while(!q.empty()) q.pop();
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
