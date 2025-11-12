#include<bits/stdc++.h>
using namespace std;
long long n,m,x,f[1005],cnt,c,r,k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            if(i==1&&j==1){
                k=x;
            }
            f[x]++;
        }
    }
    for(int i=100;i>=k;i--){
        if(f[i]==1){
            cnt++;
        }
    }
    if((cnt/n)%2==0){
        if(cnt%n==0){
            cout<<cnt/n<<' '<<1;
            return 0;
        }
        else{
            cout<<cnt/n+1<<' '<<cnt%n;
            return 0;
        }
    }
    else{
        if(cnt%n==0){
            cout<<cnt/n<<' '<<n;
            return 0;
        }
        else{
            cout<<cnt/n+1<<' '<<n-cnt%n+1;
            return 0;
        }
    }
    return 0;
}
