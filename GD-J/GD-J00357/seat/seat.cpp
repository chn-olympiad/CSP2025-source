#include<bits/stdc++.h>
using namespace std;
int a[11][11],n,m,g[1000],p,cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>g[i];
    p=g[1];
    sort(g+1,g+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2==1){
                a[j][i]=g[++cnt];
                if(g[cnt]==p) {
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
            }else{
                a[n-j+1][i]=g[++cnt];
                if(g[cnt]==p) {
                    cout<<i<<' '<<n-j+1<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}