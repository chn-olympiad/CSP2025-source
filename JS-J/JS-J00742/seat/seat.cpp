#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[12][12],b[150],c=1,d;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>b[i];
    d=b[1];
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i%2==1){
                a[j][i]=b[c];
                c++;
            }else{
                for(int k=n;k>=1;k--){
                    a[j][k]=b[c];
                    c++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]==d) cout<<j<<" "<<i;
    return 0;
}
