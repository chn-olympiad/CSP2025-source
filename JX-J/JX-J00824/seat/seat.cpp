#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
struct node{
    long long s;
    long long u;
}a[1010101];
bool cmp(node x,node y){
    return x.u>y.u;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].u;
        a[i].s=i;
    }
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].s==1){
            cnt=i;
            break;
        }
    }
    long long _=((cnt-1)/n)+1;
    long long __=(cnt-1)%n+1;

    if(_%2==1){
        cout<<_<<" "<<__;
    }else{
        cout<<_<<" "<<n-__+1;
    }
    return 0;
}
