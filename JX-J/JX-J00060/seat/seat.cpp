#include <bits/stdc++.h>
using namespace std;
int t=1,d,n,m,s,x,y,g=1;
bool f;
struct Aaa{
    int id;
    int k;
};
Aaa a[300];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].k;
        a[i].id=i;
    }
    for(int i=1;i<=n*m;i++)
    {
        for(int j=m*n;j>=i;j--)
        {
            if(a[j].k>a[i].k)
            {
                int t=a[i].k;
                a[i].k=a[j].k;
                a[j].k=t;
                int l=a[i].id;
                a[i].id=a[j].id;
                a[j].id=l;
            }
        }
    }
    for(int i=1,j=0;i<=n*m;i++)
    {
        if(a[i].id==1)
        {
            x=t;
            y=g;
            break;
        }
        if(g==n&&j==0)
        {
            j=1;
            t++;
            continue;
        }
        else if(g==1&&j==1)
        {
            j=0;
            t++;
            continue;
        }
        if(j==0)
        {
            g++;
        }
        else
        {
            g--;
        }

    }
    cout<<x<<" "<<y;
}
