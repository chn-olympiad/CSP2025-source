//100
//100
//100
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c = 1,r = 1;

struct Node{
    ll id,w;
}a[100005];
bool cmp(Node x,Node y){
    return x.w>y.w;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i = 1;i<=n*m;i++){
        cin>>a[i].w;
        a[i].id = i;
    }
    ll op = 1;
    sort(a+1,a+n*m+1,cmp);
    for(ll i = 1;i<=n*m;i++){
        if(a[i].id==1) {
            cout<<c<<" "<<r<<endl;
            return 0;
        }
        if(op==1){
            if(r+1>n){
                op = 2;
                c++;
            }
            else r++;
        }
        else if(op==2){
            if(r-1<1){
                op = 1;
                c++;
            }
            else r--;
        }

    }
    return 0;
}
