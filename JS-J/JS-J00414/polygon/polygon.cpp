#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n;
int a[5010];
void d(int w,int cnt,int ma,int m)
{
    if(m==0)
    {
        if(cnt>ma*2) ans++;
        return;
    }
    if(w>n) return;
    d(w+1,cnt+a[w],max(a[w],ma),m-1);
    d(w+1,cnt,ma,m);
    return;
}
void lesson1()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++)
    {
        d(1,0,0,i);
        ans%=998244353;
    }
    cout<<ans;
}
int main()
{
    freopen(polygon.in,"r",stdin);
    freopen(polygon.out,"w",stdout);
    lesson1();
    return 0;
}
