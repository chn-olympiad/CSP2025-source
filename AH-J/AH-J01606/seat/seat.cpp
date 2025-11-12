#include<bits/stdc++.h>
using namespace std;
#define int long long
int sqz(int x,int y)
{
    if(x%y==0 ) return x/y;
    else return x/y+1;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,sum=1,v;
    cin>>n>>m>>v;
    for(int i=1;i<n*m;i++)
    {
        int x;
        cin>>x;
        if(x>v) sum++;
    }

    int l=sqz(sum,n),h;
    if(l%2==1)
    {
        h=sum%n;
    }
    else{
        h=n+1-sum%n;
    }
    if(h==0) h=n;
    cout<<l<<" "<<h<<endl;
    return 0;
}
