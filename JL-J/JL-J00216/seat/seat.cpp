#include<bits/stdc++.h>
using namespace std;
long long s[105],bb[15][15],dd[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,ss;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>s[i];
    }
    ss=s[1];
    sort(s+1,s+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        dd[n*m+1-i]=s[i];
    }
    long long zz=1,ma=0;
    for(int z=1;z<=m;z++)
    {
        if(zz==1)
        {
            for(int i=1;i<=n;i++)
            {
                ma++;
                bb[i][z]=dd[ma];
            }
            zz=-1;
        }
        else if(zz==-1)
        {
            for(int i=n;i>=1;i--)
            {
                ma++;
                bb[i][z]=dd[ma];
            }
            zz=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {

            if(bb[i][j]==ss)
            {
                cout<<j<<" "<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
