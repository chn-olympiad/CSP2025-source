#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val,place;
    friend bool operator < (node a,node b)
    {
        return a.val<b.val;
    }
};
int t,n,cnt[4],minn[4],place[4];
int a[100005][4];
int main()
{
    freopen("club2.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        memset(cnt,0,sizeof(cnt));
        memset(place,0,sizeof(place));
        memset(minn,0x3f,sizeof(minn));
        priority_queue<node> q1;
        priority_queue<node> q2;
        priority_queue<node> q3;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(int i=1;i<=n;i++)
        {
            int maxx=-1,who;
            for(int j=1;j<=3;j++)
            {
                int num=a[i][j];
                if(cnt[j]==(n/2))
                {
                    if(j==1&&!q1.empty())
                    {
                        num-=q1.top().val;
                        q1.pop();
                    }
                    else if(j==2&&!q2.empty())
                    {
                        num-=q2.top().val;
                        q2.pop();
                    }
                    else if(j==3&&!q3.empty())
                    {
                        num-=q3.top().val;
                        q3.pop();
                    }
                    num+=place[j];
                    cnt[j]--;
                }
                if(num>=maxx)
                {
                    maxx=num;
                    who=j;
                }
                else if(num==maxx)
                {
                    if(cnt[j]<cnt[who])
                    {
                        who=j;
                    }
                }
            }
            //cout<<who<<" "<<maxx<<endl;
            if(who==1)
            {
                ans+=maxx;
                q1.push({(a[i][who]-place[who]),i});
                place[who]=max(a[q1.top().place][2],a[q1.top().place][3]);
            }
            else if(who==2)
            {
                ans+=maxx;
                q2.push({(a[i][who]-place[who]),i});
                place[who]=max(a[q2.top().place][1],a[q2.top().place][3]);
            }
            else
            {
                ans+=maxx;
                q3.push({(a[i][who]-place[who]),i});
                place[who]=max(a[q3.top().place][2],a[q3.top().place][1]);
            }
            cnt[who]=min(cnt[who]+1,n);
        }
        cout<<ans<<endl;
    }
    return 0;
}
