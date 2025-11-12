#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fr(xx,aa,bb) for(xx=aa;xx<=bb;xx++)
#define rf(xx,aa,bb) for(xx=aa;xx>=bb;xx--)
const ll N=5e6;
const ll inf=0x3f3f3f3f;
const ll Inf=0x3f3f3f3f3f3f3f3f;

int n,m,c,r,mk0,mk1,cnt=1,a[N];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll i,j,k,l;

    cin>>n>>m>>mk0;
    fr(i,2,n*m)cin>>mk1,cnt+=mk1>mk0;
    c=cnt/n+(cnt%n!=0),
    r=cnt%n;
    if(r==0)r=n;
    if(c%2==0)r=n-r+1;
    cout<<c<<' '<<r;

    // fprintf(stderr,"used time = %ldms\n\n",1000*clock()/CLOCKS_PER_SEC);
    return 0;
}
/*

*/
//g++ seat.cpp -o seat -O2 -std=c++14 -static