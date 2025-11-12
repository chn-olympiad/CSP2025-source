#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,tot;
struct stu{
    ll fs;
    ll id;
}a[110];
bool cmp(const stu &x,const stu &y){
    return x.fs>y.fs;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        scanf("%lld",&a[i].fs);
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    ll c=1,r=1;
    while(1){
        if(a[++tot].id==1)break;
        if(c%2!=0){
            ++r;
            if(r>n){
                --r;
                ++c;
            }
        }
        else{
            --r;
            if(r<1){
                ++r;
                ++c;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
/*
PLEASE AC!!!!!!!!!!
*/
