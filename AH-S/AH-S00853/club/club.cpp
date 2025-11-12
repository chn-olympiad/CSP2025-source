#include<bits/stdc++.h>
using namespace std;
int n,ans,t,renx;
int a[100005][4],b[100005];
bool A=1,B=1;
bool cmp1(int x,int y)
{
    return x>y;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        if(n==2)
        {
            int q,w,e,r,g,f;
            cin>>q>>w>>e>>r>>f>>g;
            ans=max(max(e+r,e+f),max(max(q+f,q+g),max(w+r,w+g)));
            cout<<ans<<endl;return 0;
        }
        renx=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0)
            {
                A=0;
            }
            if(a[i][3]!=0)
            {
                A=0;B=0;
            }
        }
        if(A)
        {
            for(int i=1;i<=n;i++)
            {
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1,cmp1);
            for(int i=1;i<=renx;i++)
            {
                ans+=b[i];
            }
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}
