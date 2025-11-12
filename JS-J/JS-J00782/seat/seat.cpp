#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int tmp=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[n*m-i+1]==tmp)tmp=i;
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                ans++;
                if(ans==tmp){
                    cout<<i<<' '<<j;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                ans++;
                if(ans==tmp){
                    cout<<i<<' '<<j;
                }
            }
        }
    }
    return 0;
}
