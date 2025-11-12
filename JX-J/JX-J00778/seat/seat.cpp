#include<bits/stdc++.h>
using namespace std;
int n,m,p,pp;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    p=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==p){
            pp=i;
            break;
        }
    }
    if(((pp-1)/n+1)%2==0) {
        if(pp%n==0) cout<<((pp-1)/n+1)<<" "<<1;
        else cout<<((pp-1)/n+1)<<" "<<n-(pp%n)+1;
    }
    else {
        if(pp%n==0) cout<<((pp-1)/n+1)<<" "<<n;
        else cout<<((pp-1)/n+1)<<" "<<(pp%n);
    }
}
