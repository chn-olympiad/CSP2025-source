#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
long long R,n,m,a[1005]={0},c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++) cin>>a[i];
    R=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==R){
            c=i/n+1;
            if(c%2==0){
                r=n-i%n;
            }else{
                r=i+1-n*(c-1);
            }
            cout<<c<<' '<<r;
            return 0;
        }
    }
    return 0;
}
