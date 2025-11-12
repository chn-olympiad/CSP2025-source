#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long y,t,n,m,a[N],c=1,r=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    y=a[1];
    sort(a+1,a+t+1);
    for(int i=1;i<=t;i++){
        if(c>m) break;
        if(r>n){
            c++;
            r=1;
        }
        if(a[i]==y){
            cout<<c<<' '<<r;
            return 0;
        }
        r++;
    }
    return 0;
}
