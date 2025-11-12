#include<bits/stdc++.h>
using namespace std;
int n,m,a[200][200],s[400030],p=0,q=0,t=0;
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
          cin>>s[i];
    }
        q=s[1];
        sort(s+1,s+1+n*m);
    p=n*m+1;
    for(int j=1;j<=m;j++){
            if(t==1)break;
        if(j%2==0){
             for(int i=n;i>=1;i--){
            p--;
            a[i][j]=s[p];
            if(a[i][j]==q){
                cout<<j<<" "<<i;
                t=1;
                break;
            }

             }
        }
        else{
            for(int i=1;i<=n;i++){
            p--;
            a[i][j]=s[p];
                if(a[i][j]==q){
                cout<<j<<" "<<i;
                t=1;
                break;
            }
             }
        }
    }
    return 0;
}
