#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    int sc;
    bool f=false;
}b[200];
bool cmp(node x,node y)
{
    return x.sc>y.sc;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    b[0].f=true;
    cin>>b[0].sc;
    for(int i=1;i<m*n;i++)
    {
        cin>>b[i].sc;
    }
    sort(b,b+m*n,cmp);
    int y=0;
    for(int i=0;i<m*n;i++)
    {
        if(b[i].f==true)
        {
            y=i+1;
            break;
        }
    }
    int o=y/n;
    int p=y%n;
    if(y%n!=0)
    {
        o++;
        if(m%2==0)
        {
            p=m-p+1;
        }
    }
    else
    {
        p=m;
    }
    cout<<o<<" "<<p;
    return 0;
}
