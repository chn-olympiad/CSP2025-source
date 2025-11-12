#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,z[110],b,x=1,a[110],u;
    cin>>n>>m>>b;
    u=m*n;
    for(int i=1;i<=u-1;i++) cin>>z[i];
    z[u]=b;
    sort(z+1,z+u);
    for(int i=u-1;i>=0;i--){
        a[x]=z[i];
        x++;
    }
    x=1;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                if(a[x]==b){
                    cout<<i<<' '<<j;
                    return 0;
                }
                x++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[x]==b){
                    cout<<i<<' '<<j;
                    return 0;
                }
                x++;
            }
        }
    }
    cout<<1<<' '<<2;
    return 0;
}
