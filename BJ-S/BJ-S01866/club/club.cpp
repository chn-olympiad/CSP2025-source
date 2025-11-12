#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct node{
    int x,y,z;
}a[N];
int n;
bool cmp(node p,node q)
{
    return p.x>q.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++)
        {
            ans+=a[i].x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
