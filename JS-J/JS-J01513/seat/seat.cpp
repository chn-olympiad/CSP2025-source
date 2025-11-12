#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],k,x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    k=n*m+1;
    for(int i=1;i<=n*m;i++)cin>>b[i];
    x=b[1];
    sort(b+1,b+1+n*m);
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            k--;
            if(j%2==1&&b[k]==x){
                cout<<j<<' '<<i;
                return 0;
            }
            else if(j%2==0&&b[k]==x){
                cout<<j<<' '<<n-i+1;
                return 0;
            }
        }
    }
    return 0;
}
