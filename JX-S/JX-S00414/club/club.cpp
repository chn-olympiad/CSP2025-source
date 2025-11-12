#include <bits/stdc++.h>
using namespace std;
#define int long long
struct clubs{
    int d,club,id;
    bool operator < (const clubs& y) const{
        return d>y.d;
    }
};
priority_queue<clubs> club1;
priority_queue<clubs> club2;
priority_queue<clubs> club3;
priority_queue<clubs> empty_;
int a[100005][3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        int n;
        scanf("%lld",&n);
        club1=empty_;
        club2=empty_;
        club3=empty_;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
            {
                ans+=a[i][0];
                if(a[i][1]>=a[i][2])
                {
                    club1.push({a[i][0]-a[i][1],2,i});
                }
                else
                {
                    club1.push({a[i][0]-a[i][2],3,i});
                }
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])
            {
                ans+=a[i][1];
                if(a[i][0]>=a[i][2])
                {
                    club2.push({a[i][1]-a[i][0],1,i});
                }
                else
                {
                    club2.push({a[i][1]-a[i][2],3,i});
                }
            }
            else
            {
                ans+=a[i][2];
                if(a[i][0]>=a[i][1])
                {
                    club3.push({a[i][2]-a[i][0],1,i});
                }
                else
                {
                    club3.push({a[i][2]-a[i][1],2,i});
                }
            }
        }
        while(club1.size()>n/2||club2.size()>n/2||club3.size()>n/2)
        {
            if(club1.size()>n/2)
            {
                clubs tmp=club1.top();
                club1.pop();
                ans-=tmp.d;
                if(tmp.club==2)
                {
                    club2.push({a[tmp.id][1]-a[tmp.id][2],3,tmp.id});
                }
                else
                {
                    club3.push({a[tmp.id][2]-a[tmp.id][1],2,tmp.id});
                }
            }
            else if(club2.size()>n/2)
            {
                clubs tmp=club2.top();
                club2.pop();
                ans-=tmp.d;
                if(tmp.club==1)
                {
                    club1.push({a[tmp.id][0]-a[tmp.id][2],3,tmp.id});
                }
                else
                {
                    club3.push({a[tmp.id][2]-a[tmp.id][0],1,tmp.id});
                }
            }
            else
            {
                clubs tmp=club3.top();
                club3.pop();
                ans-=tmp.d;
                if(tmp.club==1)
                {
                    club1.push({a[tmp.id][0]-a[tmp.id][1],2,tmp.id});
                }
                else
                {
                    club2.push({a[tmp.id][1]-a[tmp.id][0],1,tmp.id});
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
