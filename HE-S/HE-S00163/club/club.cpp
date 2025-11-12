#include<bits/stdc++.h>
using namespace std;
int n,j,maxzhi;
const int IMIN=-999;
long long arr[100000][7];
stack<long long>maxmm;
int main(){
    cin>>n;j;
    int ax=0;
    maxmm.push(IMIN);
    if(n=2){
       for(int jj=1;jj<=j;jj++){
        for(int i=1;i<=n;i++){
            cin>>arr[jj][i];
        }
       }
      int l=1;
      for(int i=1;i<=n;i++){
       for(int n=1;n+1<=j;n++){
           if(arr[i][n]<arr[i][n+1]){
            int m=max(arr[i][n],arr[i][n+1]);
            if(m>maxmm.top()){
                maxmm.push(m);
            }
           }
           else if(arr[i][n]==arr[i][n+1]){
            continue;
           }
           else if(arr[i][n]>arr[i][n+1]){
            int m1=max(arr[i][n],arr[i][n+1]);
            if(m1>maxmm.top()){}
            maxmm.push(m1);
           }
       }
      }
      for(int j=1;j<=n-2;j++){
        maxzhi+=maxmm.top();
        maxmm.pop();
      }
       cout<<maxzhi<<'\n';
       return 0;
    }
}
