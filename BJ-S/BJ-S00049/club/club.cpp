#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int pos[100005][5];
int n;
int ans;
int cnt[5];
struct T
{
    int d1,d2,p;
    friend bool operator<(T a,T b)
    {
        return a.d1>b.d1;
    }
};
priority_queue<T> q[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        while(!q[1].empty())q[1].pop();
        while(!q[2].empty())q[2].pop();
        while(!q[3].empty())q[3].pop();
        cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)cin>>a[i][j];
            if(a[i][1]>a[i][2])
            {
                if(a[i][2]>a[i][3])pos[i][1]=1,pos[i][2]=2,pos[i][3]=3;
                else if(a[i][3]<a[i][1])pos[i][1]=1,pos[i][2]=3,pos[i][3]=2;
                else pos[i][1]=3,pos[i][2]=1,pos[i][3]=2;
            }
            else
            {
                if(a[i][1]>a[i][3])pos[i][1]=2,pos[i][2]=1,pos[i][3]=3;
                else if(a[i][3]<a[i][2])pos[i][1]=2,pos[i][2]=3,pos[i][3]=1;
                else pos[i][1]=3,pos[i][2]=2,pos[i][3]=1;
            }
            int k=1;
            while(1)
            {
                cnt[pos[i][k]]++;
                if(cnt[pos[i][k]]>n/2)
                {
                    cnt[pos[i][k]]--;
                    T tmp;
                    tmp.d1=100000;
                    while(tmp.d1==100000&&!q[pos[i][k]].empty())tmp=q[pos[i][k]].top(),q[pos[i][k]].pop();
                    if(tmp.d1>a[i][pos[i][k]]-a[i][pos[i][k+1]])
                    {
                        q[pos[i][k]].push(tmp);
                        k++;
                        continue;
                    }
                    ans+=a[i][pos[i][k]];
                    ans-=tmp.d1;
                    T p;
                    if(k==3)p.d1=100000;
                    else p.d1=a[i][pos[i][k]]-a[i][pos[i][k+1]];
                    if(k>=2)p.d2=100000;
                    else p.d2=a[i][pos[i][k]]-a[i][pos[i][k+2]];
                    p.p=pos[i][k+1];
                    q[pos[i][k]].push(p);
                    if(tmp.d2==100000)p.d1=100000;
                    else p.d1=tmp.d2-tmp.d1;
                    p.d2=100000;
                    for(int j=1;j<=3;j++)
                    {
                        if(j==pos[i][k])continue;
                        if(j==tmp.p)continue;
                        p.p=j;
                    }
                    q[tmp.p].push(p);
                    cnt[tmp.p]++;
                }
                else
                {
                    T p;
                    if(k==3)p.d1=100000;
                    else p.d1=a[i][pos[i][k]]-a[i][pos[i][k+1]];
                    if(k>=2)p.d2=100000;
                    else p.d2=a[i][pos[i][k]]-a[i][pos[i][k+2]];
                    p.p=pos[i][k+1];
                    q[pos[i][k]].push(p);
                    ans+=a[i][pos[i][k]];
                }
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
