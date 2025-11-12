#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int x,y,z;
}a[1000005];
int yi(node t)
{
    return max(t.x,max(t.y,t.z));
}
int er(node t)
{
    if((t.x>t.y&&t.y>t.z)||(t.x<t.y&&t.y<t.z)) return t.y;
    if((t.x>t.y&&t.x<t.z)||(t.x<t.y&&t.x>t.z)) return t.x;
    if((t.z>t.y&&t.z<t.x)||(t.z<t.y&&t.z>t.x)) return t.z;
}
int san(node t)
{
    return min(t.x,min(t.y,t.z));
}
bool cmp(node q,node p)
{
    return yi(q)-er(q)>yi(p)-er(p);
}
void solve()
{
    memset(a,0,sizeof(a));
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
    int num1=0,num2=0,num3=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(yi(a[i])==a[i].x&&num1==n/2)
        {
            if(er(a[i])==a[i].y) num2++;
            else if(er(a[i])==a[i].z) num3++;
            ans+=er(a[i]);
        }
        else if(yi(a[i])==a[i].x)ans+=yi(a[i]),num1++;
        else if(yi(a[i])==a[i].y&&num2==n/2)
        {
            if(er(a[i])==a[i].x) num1++;
            else if(er(a[i])==a[i].z) num3++;
            ans+=er(a[i]);
        }
        else if(yi(a[i])==a[i].y) ans+=yi(a[i]),num2++;
        else if(yi(a[i])==a[i].z&&num3==n/2)
        {
            if(er(a[i])==a[i].y) num2++;
            else if(er(a[i])==a[i].x) num1++;
            ans+=er(a[i]);
        }
        else if(yi(a[i])==a[i].z) ans+=yi(a[i]),num3++;
    }
    cout<<ans<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
