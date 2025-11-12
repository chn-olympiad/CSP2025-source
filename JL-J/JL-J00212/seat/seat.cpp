#include<bits/stdc++.h>
using namespace std;
int s[10005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c=n*m;
    int d=0,e=0;
    for(int i=0;i<n*m;i++)
    {
        cin>>s[i];
        if(s[0]>s[i])
        {
            c--;
        }
    }
    if(c%n==0)
    {
        d=c/n;
    }
    else{
        d=c/n+1;
    }
    cout<<d<<" ";
    if(d%2==1)
    {
        e=c-(d-1)*n;
    }
    else{
        e=n-(c-(d-1)*n)+1;
    }
    cout<<e;
    return 0;
}
