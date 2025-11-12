#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=1e9;
int n,ans;
struct nd
{
   int val,num,pos;
   bool operator <(const nd &x)const
   {
       if(val==x.val)return num<x.num;
        return val>x.val;
   }
}a[N][3];
void solve()
{
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)cin>>a[i][j].val,a[i][j].num=j;
        sort(a[i],a[i]+3);
    }
    multiset<nd>s[3];
    for(int i=1;i<=n;i++)
    {
        ans+=a[i][0].val;
        s[a[i][0].num].insert((nd){a[i][1].val-a[i][0].val,i,0});
    }
    while((int)s[0].size()>n/2||(int)s[1].size()>n/2||(int)s[2].size()>n/2)
    {
        for(int i=0;i<3;i++)
            while(s[i].size()>n/2)
            {
                nd x=(*s[i].begin());
                s[i].erase(s[i].begin());
                ans+=x.val;
                if(x.pos==1)s[a[x.num][2].num].insert((nd){-inf,i,2});
                else s[a[x.num][1].num].insert((nd){a[x.num][2].val-a[x.num][1].val,x.num,1});
            }
    }
    cout<<ans<<"\n";
}
int main()
{
   ios::sync_with_stdio(false);
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
