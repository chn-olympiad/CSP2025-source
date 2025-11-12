#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m,a[110],k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            k=i;
            break;
        }
    }
    cout<<ceil(k*1.0/n)<<' ';
    if(k%(2*n)<=n) cout<<k%(2*n);
    else cout<<2*n-k%(2*n)+1;
    return 0;
}
