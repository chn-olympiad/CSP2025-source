#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=1e3;
struct node{
    ll val,id;
}a[len];
ll n,m;
bool cmp(node x, node y){
    return x.val>y.val;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);//09:05 incredible never so fast
    cin>>n>>m;
    a[1].id=1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].val;
    }
    sort(a+1,a+m*n+1,cmp);
    ll idx=0;
    for(int j=1;j<=m;j++){
        if(j&1){
            for(int i=1;i<=n;i++){
                idx++;
                if(a[idx].id==1){
                    cout<<j<<' '<<i<<'\n';
                    return 0;
                }
            }
        }
        else{
            for(int i=n;i>=1;i--){
                idx++;
                if(a[idx].id==1){
                    cout<<j<<' '<<i<<'\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}
