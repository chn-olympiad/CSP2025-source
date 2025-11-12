#include <bits/stdc++.h>
using namespace std;
long long ans;
int t,n,cnt1,cnt2,cnt3,p,q,r;
struct stu
{
    int con,cha;
}q1[200005],q2[200005],q3[200005];
bool cmp(stu a,stu b)
{
    return a.cha<b.cha;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;cnt1=0;cnt2=0;cnt3=0;
        for(int i=1;i<=n;++i)
        {
            cin>>p>>q>>r;
            if(p>=q)
            {
                if(q>=r)
                {
                    ++cnt1;
                    q1[cnt1].con=p;
                    q1[cnt1].cha=p-q;
                }
                else    if(p>=r)
                {
                    ++cnt1;
                    q1[cnt1].con=p;
                    q1[cnt1].cha=p-r;
                }
                else
                {
                    ++cnt3;
                    q3[cnt3].con=r;
                    q3[cnt3].cha=r-p;
                }
            }
            else
            {
                if(p>=r)
                {
                    ++cnt2;
                    q2[cnt2].con=q;
                    q2[cnt2].cha=q-p;
                }
                else    if(q>=r)
                {
                    ++cnt2;
                    q2[cnt2].con=q;
                    q2[cnt2].cha=q-r;
                }
                else
                {
                    ++cnt3;
                    q3[cnt3].con=r;
                    q3[cnt3].cha=r-q;
                }
            }
        }
        for(int i=1;i<=cnt1;++i)
            ans+=q1[i].con;
        for(int i=1;i<=cnt2;++i)
            ans+=q2[i].con;
        for(int i=1;i<=cnt3;++i)
            ans+=q3[i].con;
        if(cnt1>n/2)
        {
            sort(q1+1,q1+cnt1+1,cmp);
            for(int i=1;i<=cnt1-n/2;++i)
                ans-=q1[i].cha;
        }
        else if(cnt2>n/2)
        {
            sort(q2+1,q2+cnt2+1,cmp);
            for(int i=1;i<=cnt2-n/2;++i)
                ans-=q2[i].cha;
        }
        else if(cnt3>n/3)
        {
            sort(q3+1,q3+cnt3+1,cmp);
            for(int i=1;i<=cnt3-n/2;++i)
                ans-=q3[i].cha;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
