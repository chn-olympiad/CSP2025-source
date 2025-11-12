#include <bit/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    int g[n*m],s[n*m];
    for(int i=0;i<n*m;i++)
        cin>>g[i];
    int c=g[0],c1=0;
    for(int i=0;i<n*m;i++)
    {
        int max=0;
        for(int j=0;j<n*m;j++)
        {
            if(max<g[j])
            {
                max=g[j];
                g[j]=0;
            }
        }
        s[i]=max;
    }
    for(int i=0;i<n*m;i++)
    {
        if(s[i]==c)
            c1=i+1;
    }
    int l=0,h=0;
    if(c1%n==0)
        l=c1/n;
    else
        l=(c1/n)+1;
    if(l%2==0)
        h=(n-(c1%n)+1)%n;
    else
        h=c1%n;
    cout<<l<<"  "<<h;
    return 0;
}