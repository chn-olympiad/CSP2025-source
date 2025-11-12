#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,c,r,grade=1; cin>>n>>m;
    int i=n*m-1;

    int s; cin>>s;
    while(i--)
    {
        int t;cin>>t;
        if(t>s)grade++;
    }

    c=(grade-1)/n+1;
    r=(grade-1)%n+1;
    if(c%2==0)r=n-r+1;

    cout<<c<<" "<<r<<endl;

    return 0;
}

