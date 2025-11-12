#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N]={0};
int tx[N]={0};
int n=0;
int ans=0;
void dg(int dep,int sum,int cs,bool f)
{
    if(dep>n)
    {
        if(f&&cs>3)
        {
            ans++;
          //  cout<<sum<<'\n';
            /*
            for(int i=1;i<=n;i++)
            {
                if(tx[i]!=0)
                {
                    cout<<i<<' ';
                }
            }
            cout<<'\n';*/
        }
        return;
    }

    if(sum>a[dep]||cs==1||cs==2)
    {
     //   tx[dep]=1;
        dg(dep+1,sum+a[dep],cs+1,1);
     //   tx[dep]=0;
    }
    else
    {
     //   tx[dep]=1;
       dg(dep+1,sum+a[dep],cs+1,0);
    //   tx[dep]=0;
    }
    dg(dep+1,sum,cs,f);
    return;

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("poligon.in","r",stdin);
    freopen("poligon.out","w",stdout);
    cin>>n;

    //pf
    if(n<3)
    {
        cout<<0;
        return 0;
    }else if(n==3)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3])
        {
            cout<<a[3];
            return 0;
        }else{
            cout<<0;
        }
        return 0;
    }





    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dg(1,0,1,0);
    cout<<ans%998244353;
    return 0;
}
/*
*/
