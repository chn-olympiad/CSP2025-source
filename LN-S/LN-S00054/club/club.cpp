#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long t,n;
struct node
{
    long long fl1;
}aa[N],bb[N],cc[N];
long long ans=0;
int tota,totb,totc;
bool cmp(node A,node B)
{
    return A.fl1>B.fl1;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0,tota=totb=totc=0;
        int x,y,z;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            if(x>=y&&x>=z)
            {
                ans+=x;
                aa[++tota].fl1=max(y-x,z-x);
            }
            else if(y>=x&&y>=z)
            {
                ans+=y;
                bb[++totb].fl1=max(x-y,z-y);
            }
            else
            {
                ans+=z;
                cc[++totc].fl1=max(x-z,y-z);
            }
        }
        if(tota>n/2)
        {
            sort(aa+1,aa+1+tota,cmp);
            int ing=tota-n/2;
            for(int i=1;i<=ing;i++)
                ans+=aa[i].fl1;
        }
        else if(totb>n/2)
        {
            sort(bb+1,bb+1+totb,cmp);
            int ing=totb-n/2;
            for(int i=1;i<=ing;i++)
                ans+=bb[i].fl1;
        }
        else
        {
            sort(cc+1,cc+1+totc,cmp);
            int ing=totc-n/2;
            for(int i=1;i<=ing;i++)
                ans+=cc[i].fl1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}