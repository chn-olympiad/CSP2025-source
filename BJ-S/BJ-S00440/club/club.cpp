#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],b[N],c[N],e[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    long long i,j,k,n,m,l,r,x,y,s=0,T,z,ta=0,tb=0,tc=0,te;
    cin>>T;
    while(T--)
    {
        cin>>n;
        s=0;
        ta=0;
        tb=0;
        tc=0;
        te=0;
        for(i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            if(x>y&&x>z)
            {
                a[++ta]=(x-max(y,z));
                s+=x;
            }
            else if(y>z)
            {
                b[++tb]=(y-max(x,z));
                s+=y;
            }
            else
            {
                c[++tc]=(z-max(x,y));
                s+=z;
            }
        }
        if(ta<=n/2&&tb<=n/2&&tc<=n/2)
        {
            cout<<s<<"\n";
            continue;
        }
        if(ta>n/2)
        {
            for(i=1;i<=ta;i++)
            {
                e[i]=a[i];
            }
            te=ta;
        }
        else if(tb>n/2)
        {
            for(i=1;i<=tb;i++)
            {
                e[i]=b[i];
            }
            te=tb;
        }
        else
        {
            for(i=1;i<=tc;i++)
            {
                e[i]=c[i];
            }
            te=tc;
        }
        j=te;
        sort(e+1,e+te+1);
        for(i=1;i<=te;i++)
        {
            s-=e[i];
            j--;
            if(j<=n/2) break;
        }
        cout<<s<<"\n";
    }
    return 0;
}