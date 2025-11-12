#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define file(x) (fin(x),fout(x),0)

int xxxx=file(club);

const int maxn=1e5+5;

int n;
int cnt[5];

priority_queue<int>que[4];

inline void clr()
{
    for(int i=1;i<=3;i++)
    {
        cnt[i]=0;
        while(!que[i].empty()) que[i].pop();
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        pii num[5];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++) scanf("%d",&num[j].fi),num[j].se=j;
            sort(num+1,num+3+1);
            cnt[num[3].se]++;
            ans+=num[3].fi;
            que[num[3].se].push(num[2].fi-num[3].fi);
            if(cnt[num[3].se]>n/2)
            {
                ans+=que[num[3].se].top();
                que[num[3].se].pop();
                cnt[num[3].se]--;
            }
        }
        printf("%d\n",ans);
        clr();
    }
}