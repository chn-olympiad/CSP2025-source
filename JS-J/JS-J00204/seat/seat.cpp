#include<bits/stdc++.h>
using namespace std;
int n,m,g;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s[n+1][m+1];
    int a[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    g=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==g){
            int d=(i-1)/n+1,k=(i-1)%n+1;
            if(d&1) cout<<d<<' '<<k;
            else cout<<d<<' '<<n-k+1;
            break;
        }
    }
    return 0;
}
