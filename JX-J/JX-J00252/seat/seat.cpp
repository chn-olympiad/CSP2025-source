#include<bits/stdc++.h>
using namespace std;
int a[11][11]={};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 and j==1){
                continue;
            }
            if(a[i][j]>a[1][1]){
                s++;
            }
        }
    }
   int s1=0;
   for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                s1++;
                if(s1==s+1){
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                s1++;
                if(s1==s+1){
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    return 0;
}
