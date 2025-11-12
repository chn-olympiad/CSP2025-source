#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+1+n*m,cmp);
    int x;
    for(int i=1;i<=n*m;i++){
        if(a[i]==s) {
            x=i;
            break;
        }
    }
    int l=(x+n-1)/n;
    int h=x-(l-1)*n;
    if(l%2==0){
        cout<<l<<' '<<n+1-h;
    }else{
        cout<<l<<' '<<h;
    }
    return 0;
}
// 98 99 100
