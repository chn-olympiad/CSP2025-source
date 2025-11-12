#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1);
    int cnt=0;
    for(int i=n*m;i>=1;i--){
        if(a[i]==r){
            cnt=n*m-i+1;
            break;
        }
    }
    int p,q;
    if(cnt%n==0){
        p=cnt/n;
    }
    else{
        p=cnt/n+1;
    }
    q=cnt-(p-1)*n;
    if(p%2==1){
        cout<<p<<" "<<q;
    }
    else{
        cout<<p<<" "<<n+1-q;
    }
    return 0;
}
