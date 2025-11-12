#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    //  /\ /\
    //  (^.^) {"NO thing~"}!
    // [(   )]
    //  [] []
    int x,y,z,n;
    cin>>n;
    if(n==3){
        cin>>x>>y>>z;
        int maxn=max(x,y);
        maxn=max(maxn,z);
        if((x+y+z)>maxn*2){
            cout<<1;
        }
        else cout<<"0";
    }
    else while(n--);
    return 0;
}
