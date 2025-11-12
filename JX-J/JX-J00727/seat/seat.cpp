#include<bits/stdc++.h>
using namespace std;
const int N=13;
int n,m,a[N*N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int q=a[1],id=n*m+1;
    sort(a+1,a+(n*m)+1);
    for(int i=1;i<=m;i++){
        if(i&1){
            for(int j=1;j<=n;j++){
                id--;
                if(a[id]==q){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                id--;
                if(a[id]==q){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}