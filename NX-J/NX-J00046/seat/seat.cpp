#include<bits/stdc++.h>
using namespace std;
int ji[2000005];
int s[1005][1005];
int main()
{
    int n,m,xs=0,r,c,zu;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n*m;i++)
    {
        cin>>ji[i];
        if(i==0) xs=ji[i];


    }
    sort(ji,ji+n*m);
    for(long long i=n*m;i>0;i--)
    {
        if(ji[i]==xs) zu=(n*m)-i;
        //cout<<ji[i];
    }


    r=zu/n;
    c=zu%m;
    if(zu==n||zu==m) cout<<r<<" "<<c;
    else cout<<r+1<<" "<<c;
    return 0;
}

