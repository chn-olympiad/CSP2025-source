#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],mp[110][110];
bool c(int x,int y){return x>y;};
int main(){
    freopen("seat.in","r",stdin)
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int t=a[1];
    sort(a+1,a+1+n,c);
    int k=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                mp[j][i]=a[k];
                k++;
            }
        }else{
            for(int j=n;j>=1;j--){
                mp[j][i]=a[k];
                k++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==t){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
