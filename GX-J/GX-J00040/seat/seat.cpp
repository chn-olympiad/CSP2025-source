#include <bits/stdc++.h>
using namespace std;

int m,n,v[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    int x;
    for(int i=1;i<=n*m;i++)
    {
        cin>>v[i];
        if(i==1)    x=v[i];
    }
    sort(v+1,v+m*n+1);

    int i=1,j=1,w=1;
    for(int k=m*n;k>0;k--)
    {
        if(x==v[k])
        {
            cout<<j<<' '<<i<<endl;
            break;
        }
        if(i<n && w==1) i++;
        else if(i>1 && w==-1)   i--;
        else
        {
            j++;
            w=-w;
        }
    }
    return 0;
}
