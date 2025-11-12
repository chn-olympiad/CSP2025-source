#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,i,x,p,s=1;
    cin>>n>>m>>x;
    
    for(i=1;i<=n*m-1;i++)
    {
        cin>>p;
        if(p<x) s+=1;
    }
    cout<<s<<" "<<1;
    return 0;
}
