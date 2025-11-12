# include <bits/stdc++.h>
using namespace std;
int n,m,a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++) cin>>a[i];
    int cnt=1;
    for(int i=2; i<=n*m; i++){
        if(a[i]>a[1]) cnt++;
    }
    int t=(cnt+n-1)/n;
    cout<<t<<" ";
    if(t%2==1){
        int f=cnt-cnt/n*n;
        if(f==0) cout<<n;
        else     cout<<cnt-cnt/n*n;
    }
    else       cout<<n-(cnt-cnt/n*n);
    return 0;
}
