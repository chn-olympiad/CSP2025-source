#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,a[111];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int R=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    int pos=1;
    for(int i=1;i<=m;i++){
        if(i&1){
            for(int j=1;j<=n;j++,pos++){
                if(a[pos]==R){
                    cout<<i<<" "<<j<<endl;
                    return;
                }
            }
        }else{
            for(int j=n;j>=1;j--,pos++){
                if(a[pos]==R){
                    cout<<i<<" "<<j<<endl;
                    return;
                }
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
/*
O(n*m log n*m+n*m) 100pts
*/