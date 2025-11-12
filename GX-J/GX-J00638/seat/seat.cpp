#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,rc,s,p=1;
    cin>>n>>m;
    cin>>rc;
    for(int i=1;i<n*m;i++)
    {
        cin>>s;
        if(s>rc)
            p++;
    }
    int mj,nj,k;
    if(p==p/n*n){
        nj=n;
        mj=p/n;
    }
    if(p!=p/n*n){
        if(p/n%2==0){
            nj=p%n;
            mj=p/n+1;
        }
        else{
            nj=n-p%n+1;
            mj=p/n+1;
        }
    }
    cout<<mj<<' '<<nj;
    return 0;
}
