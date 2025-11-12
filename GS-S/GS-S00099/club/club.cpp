#include<bits/stdc++.h>
using namespace std;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n,k;

int main(){
    int a[10000000][10000000];
    int b[10000000][10000000];
    cin>>n>>t;
    for(int i=1;i<=t;++i){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=3;++j){
                    cin>>a[i][j];
                    max(a[i][j],max(a[i][j+1],a[i][j+2]));
                    a[i][j]+=a[i][j];
                    b[1][1]=a[i][j];
                }
            }
            cout<<b[1][1];
   }
    return 0;
}
