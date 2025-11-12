#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
struct node{
    ll s,p;
}a[105];
bool cmp(node a,node b){
    return a.s>b.s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>a[i].s;
        a[i].p=i;
    }
    sort(a+1,a+n*m+1,cmp);
    ll r=1,c=1;
    for(ll i=1;i<=n*m;i++){
        if(a[i].p==1){
            cout<<c<<" "<<r<<"\n";
            return 0;
        }
        if(c%2){
            if(r==n)
                c++;
            else
                r++;
        }
        else{
            if(r==1)
                c++;
            else
                r--;
        }
    }
    return 0;
}
