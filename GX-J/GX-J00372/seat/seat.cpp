#include<bits/stdc++.h>
using namespace std;
int n,m,s[20][20],x[110],t,k;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=n*m;i++){
        cin>>x[i];
    }
    t=x[1];
    sort(x+1,x+n*m+1);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(x[k]==t){
                    cout<<i<<' '<<j;
                    return 0;
                }
                k--;
            }
        }else{
            for(int j=m;j>=1;j--){
                if(x[k]==t){
                    cout<<i<<' '<<j;
                    return 0;
                }
                k--;
            }
        }
    }
    return 0;
}
