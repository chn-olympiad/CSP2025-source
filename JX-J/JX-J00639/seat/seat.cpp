#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[205],l,r;
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    l=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==l){
            r=i;
            break;
        }
    }
    cout<<(r-1)/m+1<<" "<<(((r-1)/m+1)%2==1?r-n*((r-1)/m):n-(r-n*((r-1)/m)-1));
    return 0;
}
