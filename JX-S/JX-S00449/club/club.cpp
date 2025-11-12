#include<bits/stdc++.h>
#define ll long long
const ll maxn=1000050;
using namespace std;
ll s;
struct ch
{
    ll a1,a2,a3,m;
}f,t[maxn];
bool cmp(ch xx,ch yy)
{
    /*if(xx.m==yy.m)
    {*/
        if(xx.a1==yy.a1)
        {
            if(xx.a2==yy.a2)
            {
                return xx.a3>yy.a3;
            }
            return xx.a2>yy.a2;
        }
        return xx.a1>yy.a1;
    /*}
    return xx.m<yy.m;*/
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>s;
    while(s--)
    {
        ll n=0,x=0,a[100050][5];
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
            t[i].a1=a[i][1];
            t[i].a2=a[i][2];
            t[i].a3=a[i][3];
            t[i].m=t[i].a1+t[i].a2+t[i].a3;
        }
        sort(t+1,t+1+n,cmp);
        /*for(int i=1;i<=n;i++)
        {
            cout<<t[i].a1<<" "<<t[i].a2<<" "<<t[i].a3<<endl;
        }*/
        for(int i=1;i<=n;i++)
        {
            if(((t[i].a1>=t[i].a2 && t[i].a1>=t[i].a3) && f.a1==0) || ((t[i].a1>=t[i].a2 || t[i].a1>=t[i].a3) && f.a1<(n/2) && f.a1>0))
            {
                x+=t[i].a1;
                f.a1++;
                //cout<<" "<<i<<" "<<"a1"<<" "<<x<<endl;
            }
            else if(/*((t[i].a2>=t[i].a1 && t[i].a2>=t[i].a3) && f.a2==0) || */((t[i].a2>=t[i].a1 || t[i].a2>=t[i].a3) && f.a2<(n/2)))
            {
                x+=t[i].a2;
                f.a2++;
                //cout<<" "<<i<<" "<<"a2"<<" "<<x<<endl;
            }
            else if(/*t[i].a3>=t[i].a1 && t[i].a3>=t[i].a2 && */f.a3<(n/2))
            {
                x+=t[i].a3;
                f.a3++;
                //cout<<" "<<i<<" "<<"a3"<<" "<<x<<endl;
            }
        }
        cout<<x<<endl;
        f.a1=f.a2=f.a3=0;
        for(int i=1;i<=n;i++)
        {
            t[i].a1=t[i].a2=t[i].a3=0;
        }
    }
    return 0;
}
