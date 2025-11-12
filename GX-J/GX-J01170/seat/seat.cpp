#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[101],wo,x;
    cin>>n>>m;
    for(long long ci=1;ci<=(n*m);ci++)
    {
        cin>>a[ci];
    }
    wo=a[1];
    sort(a+1,a+1+(n*m),cmp);
    for(long long ci=1;ci<=(n*m);ci++)
    {
        if(a[ci]==wo)
        x=ci;
    }
    while(1)
    {
        long long aaa=1,bbb=1;
        for(long long ci=1;ci<x;ci++)
        {
            if(aaa==n&&bbb%2==1)
            {
                bbb++;
                continue;
            }
            if(aaa!=n&&bbb%2==1)
            {
                aaa++;
                continue;
            }
            if(aaa==1&&bbb%2==0)
            {
                bbb++;
                continue;
            }
            if(aaa!=1&&bbb%2==0)
            {
                aaa--;
                continue;
            }
        }
        cout<<aaa<<" "<<bbb;;
        break;
    }
    return 0;
}
