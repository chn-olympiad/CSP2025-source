#include<bits/stdc++.h>
using namespace std;
long long qw[1000000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a,s,d,f,g,h;
    cin>>a>>s;
    for(int i=1;i<=a*s;i++)
    {
        cin>>qw[i];
    }
    d=qw[1];
    sort(qw+1,qw+1+a*s,greater<long long>());
    for(int i=1;i<=a*s;i++)
    {
        if(qw[i]==d)
        {
            f=i;
            break;
        }
    }
    g=(f-1)/a+1;
    cout<<g<<' ';
    f=(f-1)%a+1;
    if(g%2==1)
    {
        cout<<f;
    }
    else
    {
        cout<<a-f+1;
    }
    return 0;
}
