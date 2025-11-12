#include<bits/stdc++.h>
using namespace std;

const int maxN=105;

int n,m;

int a[maxN];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int x=a[1],s;
    sort(a+1,a+1+n*m,cmp);
    for(s=1;s<=n*m;s++)
        if(a[s]==x)
            break;
    int c,r=0;
    if((s%n)!=0)
        c=(s/n)+1;
    else
        c=s/n;
    if(c==1)
        r=s;
    else
    {
        if((c%2)!=0)
            r=s%n;
        else
            r=n-s%n+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
