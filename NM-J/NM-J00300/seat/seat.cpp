#include<bits/stdc++.h>
using namespace std;
int a[110],i,j,s[15][15],x,n,m,t,b,y,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(i=1;i<=t;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+t+1);
    for(i=1;i<=m;i++){
        if(i%2!=0){
            for(j=1;j<=n;j++){
                s[i][j]=a[t--];
                if(s[i][j]==b){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        if(i%2==0){
            for(j=n;j>=1;j--){
                s[i][j]=a[t--];
                if(s[i][j]==b){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
}
