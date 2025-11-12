#include<bits/stdc++.h>
using namespace std;

int n,m,r,a;//r means R's grade

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    int lev=n;
    for(int i=1;i<n*m;i++)
    {
        cin>>a;
        if(a>r)lev++;
        //if(a>r)cout<<"#"<<a<<">"<<r<<"\n";
    }
    //cout<<"#"<<lev<<"\n";
    if((lev+3)/n%2==1)cout<<(lev-1)%n+1;
    else cout<<n-(lev-1)%n;
    cout<<" "<<(lev+n-1)/n;
}
