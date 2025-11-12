#include<bits/stdc++.h>
using namespace std;
struct c{
    int x;
    int m;
}a[3][100005];
int c1,c2,c3,ans;
bool cmp(c xx,c y)
{
    return xx.m>y.m;
}
void so()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ca,cb,cc;
        cin>>ca>>cb>>cc;
        int mx=max(max(ca,cb),cc);
        int md=min(min(max(ca,cb),max(ca,cc)),max(cb,cc));
        int mn=min(min(ca,cb),cc);
        //cout<<mx<<md<<mn;
        if(mx==ca)
        {
            c1++;
            a[0][c1].x=mx;
            a[0][c1].m=mx-md;
            ans+=mx;
        }
        else if(mx==cb)
        {
            c2++;
            a[1][c2].x=mx;
            a[1][c2].m=mx-md;
            ans+=mx;
        }
        else
        {
            c3++;
            a[2][c3].x=mx;
            a[2][c3].m=mx-md;
            ans+=mx;
        }
    }
    //cout<<ans;
    int mxn=n/2;
    if(c1>mxn)
    {
        sort(a[0]+1,a[0]+c1+1,cmp);
        for(int i=mxn+1;i<=c1;i++)
            ans-=a[0][i].m;
    }
    if(c2>mxn)
    {
        sort(a[1]+1,a[1]+c2+1,cmp);
        for(int i=mxn+1;i<=c2;i++)
            ans-=a[1][i].m;
    }
    if(c3>mxn)
    {
        sort(a[2]+1,a[2]+c3+1,cmp);
        for(int i=mxn+1;i<=c3;i++)
        {
            ans-=a[2][i].m;
            //cout<<a[2][i].m<<' ';
        }

    }
    cout<<ans<<endl;
    c1=0;
    c2=0;
    c3=0;
    ans=0;
}
int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    //never gonna give you up~
    //never gonna let you down~
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
        so();
    return 0;
}
//旁边人好像AK了？？
