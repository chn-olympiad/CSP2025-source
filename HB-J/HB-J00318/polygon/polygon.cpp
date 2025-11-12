#include<bits/stdc++.h>
using namespace std;

const int N=5e3+10,MOD=998244353;
int n,m[N],ans=0,a[N];

bool cmp(int x,int y)
{
    return x<y;
}

int get_num(int n,int m)
{
    int cnt=1,num=n,d=1,cal=1;
    for(int i=1;i<=m;i++)
    {
        cnt*=num;
        num--;
        cal*=d;
        d++;
    }
    return cnt/cal;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>m[i];
    sort(m+1,m+n+1,cmp);
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    else if(n==3)
    {
        if(m[1]+m[2]+m[3]>2*m[3])
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    else
    {
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            if(m[i]!=1)
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            int g=n;
            while(g>=3)
            {
                ans+=get_num(n,g);
                g--;
            }
            cout<<ans%MOD;
            return 0;
        }
    }
    return 0;
}
