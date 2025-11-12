#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[5000];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s[1][1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=a[i];j++){
           if(a[0]<=a[i]){
               s[j]+=1;
               if(s[j]==m){
                   s[i]+=1;
                   s[j]=1;
               }
           }
           if(a[i]>a[0]){
               s[i][j]=a[0][j-1];
           }
        }
    }
    cout<<s[i][j];
    return 0;
}
