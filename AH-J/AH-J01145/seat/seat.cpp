#include<bits/stdc++.h>
using namespace std;
//map<int,long long> t;
long long i,j,n,m;
struct node{
    int name,s;
}a[200];
int cmp(node a,node b)
{
    return a.s>b.s;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
    {
        cin>>a[i].s;
        a[i].name=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(i=1;i<=n*m;i++)
    {
        if(a[i].name==1)
        {
            if(i%(2*n)==0)
            {
                cout<<1<<" "<<i/n;
            }
            else if(i%(2*n)>n)
            {
                cout<<n+n-i%(2*n)+1<<" "<<i/n+1;
            }
            else if(i%(2*n)==n)
            {
                cout<<n<<" "<<i/n;
            }
            else
            {
                cout<<i%(2*n)<<" "<<i/n+1;
            }
        }
    }
    return 0;
}

