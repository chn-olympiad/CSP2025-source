#include<bits/stdc++.h>
using namespace std;
int n,k;
#define o 500005
int a[o];
int jz[o][25];
int twcmp(int x){
    int a=x;
    if(a%2!=0){
        jz[a][1]=1;
        x--;
    }
    for(int i=20;i>=1;i--){
        if(x==pow(2,i)){
            jz[a][i+1]=1;
            return 0;
        }
        else if(x>pow(2,i)){
            x-=pow(2,i);
            jz[a][i+1]=1;
        }
    }
}
//int xor(int a,int b){
//   for(int i=25;jz[a][i]==1 || jz[b][i]==1;i--){
//
//  }
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        twcmp(a[i]);
    }
    if(n<=2 and k==0) cout<<n;
}
