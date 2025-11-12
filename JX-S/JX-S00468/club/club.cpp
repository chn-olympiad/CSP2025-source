#include<bits/stdc++.h>
using namespace std;
long long t,n,a[5000][5000],s,m,x;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        s=0,m=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                x=max(x,a[i][j]);
            }
            m+=x;
            x=0;
        }
        if(n==2){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(j==k) continue;
                    else s=max(s,a[1][j]+a[2][k]);
                    //cout<<a[1][j]+a[2][k]<<" "<<s<<endl;
                }
            }
        }
        if(n==2) cout<<s<<endl;
        else cout<<m<<endl;
    }
    return 0;
}
