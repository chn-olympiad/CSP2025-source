#include<bits/stdc++.h>
using namespace std;
struct club
{
   int a,b,c;
}cl[100005];
bool  cmp(club x,club y)
{
    if(x.a==y.a)
    {
        if(x.b==y.b)
            return x.c>y.c;
        else
            return x.b>y.b;
    }
    return x.a>y.a;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<100005;i++)
            cl[i].a=cl[i].b=cl[i].c=0;
        int n,suma=0,sumb=0,sumc=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>cl[i].a>>cl[i].b>>cl[i].c;
            suma+=cl[i].a;sumb+=cl[i].b;sumc+=cl[i].c;
        }
        sort(cl+1,cl+n+1,cmp);
        int ans1=0,ans2=0;
        for(int i=1;i<=n/2;i++)
            ans1+=cl[i].a;
        for(int i=n/2+1;i<=n;i++)
            ans1+=cl[i].b;
        for(int i=1;i<=n/2;i++)
            ans2+=cl[i].b;
        for(int i=n/2+1;i<=n;i++)
            ans2+=cl[i].a;
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}
