#include<bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freclose("seat.out","w",stdout);
int n,m,x;
int b[105];
int main(){
    scanf("%d%d",&n,&m);
    int cnt=m*n;
    for(int i=1;i<=m*n;i++){
        scanf("%d",&x);
        b[i]=x;
    }
    int k=b[1];
    sort(b+1,b+m*n+1);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
               
                if(b[cnt]==k){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt--;
            }
        }
        else{
            for(int j=n;j>=1;j--){
               
                if(b[cnt]==k){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt--;
            }
        }
    }
    return 0;
}

    