#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct cj{
    long long s,id;
}a[105];
bool cmp(cj x,cj y){
    return x.s>y.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i].s;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(long long i=1;i<=n*m;i++){
        if(a[i].id==1){
            long long x=i/n+1,y=i%n;
            if(y==0){
                y=n;
                x=i/n;
            }
            if(x%2==1){
                cout<<x<<' '<<y;
            }else{
                cout<<x<<' '<<n-y+1;
            }
            break;
        }
    }
    return 0;
}
