#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[200];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int num;
    num=b[1];
    sort(b+1,b+n*m+1,greater<int>());
    int idx;
    for(int i=1;i<=n*m;i++){
        if(b[i]==num){
            idx=i;
            break;
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(i%2){
           for(int j=1;j<=n;j++){
               cnt++;
               if(cnt==idx){
                   cout<<i<<" "<<j;
                   return 0;
               }

           }
        }
        else{
            for(int j=n;j>=1;j--){
               cnt++;
               if(cnt==idx){
                   cout<<i<<" "<<j;
                   return 0;
               }
           }
        }
    }
    return 0;
}
