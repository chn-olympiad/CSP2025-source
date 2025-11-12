#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node
{
    int a,b,c;
}a[N];
bool cmpa(node x,node y)
{
    return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
}
bool cmpb(node x,node y)
{
    return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
}
bool cmpc(node x,node y)
{
    return x.c-max(x.a,x.b)>y.c-max(y.a,y.b);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0,ac=0,bc=0,cc=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c)  ac++,sum+=a[i].a;
            else if(a[i].b>=a[i].a&&a[i].b>=a[i].c) bc++,sum+=a[i].b;
            else    cc++,sum+=a[i].c;
        }
        if(max(ac,max(bc,cc))<=n/2) cout<<sum<<'\n';
        else
        {
            sort(a+1,a+n+1,cmpa);
            int ansa=0;
            for(int i=1;i<=n/2;i++) ansa+=a[i].a;
            for(int i=n/2+1;i<=n;i++)   ansa+=max(a[i].b,a[i].c);
            sort(a+1,a+n+1,cmpb);
            int ansb=0;
            for(int i=1;i<=n/2;i++) ansb+=a[i].b;
            for(int i=n/2+1;i<=n;i++)   ansb+=max(a[i].a,a[i].c);
            sort(a+1,a+n+1,cmpc);
            int ansc=0;
            for(int i=1;i<=n/2;i++) ansc+=a[i].c;
            for(int i=n/2+1;i<=n;i++)   ansc+=max(a[i].a,a[i].b);
            cout<<max(ansa,max(ansb,ansc))<<'\n';
        }
    }
    return 0;
}
