#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,c=1,r=1,a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int flag=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        c=ceil(i*1.0/n);
        if(i%n!=1){
            if(c%2) r++;
            else r--;
        }
        if(flag==a[i]) cout<<c<<' '<<r;
    }
    return 0;
}
