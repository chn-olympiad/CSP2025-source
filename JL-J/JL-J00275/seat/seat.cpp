#include <bits/stdc++.h>
using namespace std;
long long n,m,t,w;
long long s[1111];
long long ss[111][111];
long long hs,ls;
bool cmp(int aa,int bb)
{
    return aa>bb;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++)
    {
        cin>>s[i];
    }
    int cc=s[1];
    sort(s+1,s+t+1,cmp);
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            w++;
            ls=j;
            if(j%2!=0)
            {
                hs=i;
            }
            else
            {
                hs=n+1-i;
            }
            if(s[w]==cc)
            {
                cout<<ls<<" "<<hs<<endl;
                return 0;
            }
        }
    }
    return 0;
}
