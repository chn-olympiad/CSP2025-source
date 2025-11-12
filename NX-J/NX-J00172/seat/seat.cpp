#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+10;
ll n,m,a[N],c,cnt=1,ans[N][N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    c=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                ans[i][j]=a[n*m-cnt+1];
                cnt++;
            }
        }
        else{
             for(int j=m;j>=1;j--){
                ans[i][j]=a[n*m-cnt+1];
                cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==c){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
