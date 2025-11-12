#include<bits/stdc++.h>
using namespace std;
const int N=11;
const int M=11;
int s[N][M];
int p[101];
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
   cin>>n>>m;
   int k=n*m;
   for(int i=1;i<=k;i++){
    cin>>p[i];
   }
   int r=p[1];
   sort(p,p+k+1);
   for(int i=1;i<=m;i++){
    if(i%2==0){
        for(int j=n;j>=1;j--){
            s[j][i]=p[k];
            k--;
        }
    }
    else{
          for(int j=1;j<=n;j++){
        s[j][i]=p[k];
        cout<<s[j][i];
        k--;
       }
    }
   }
   for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(s[j][i]==r){
            cout<<i<<" "<<j<<endl;
            return 0;
        }
    }
   }
   return 0;
}
