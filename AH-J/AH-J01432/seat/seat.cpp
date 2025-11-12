#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[110],c=0;
bool cmp(LL x,LL y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n*m;i++){
        cin>>a[i];
    }
    LL r=a[1];
    sort(a+1,a+n*m+1,cmp);
    LL h=1,l=1;
    for(LL i=1;i<=n*m;i++){
        if(a[i]==r){
            cout<<l<<" "<<h;
            break;
        }
        if(c==0){
            h++;
            if(h>n){
                h=n;
                l++;
                c=1;
            }
        }
        else{
            h--;
            if(h<1){
                h=1;
                l++;
                c=0;
            }
        }
    }
    return 0;
}
