#include<bits/stdc++.h>
using namespace std;
int n,m,f=0,s;
int a[10000];
bool cmp(int x,int y){
  return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
s=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
    f++;
    if(a[f]==s){
        if(i%2==0){
            cout<<i<<' '<<1+i*n-f;
            return 0;
        }
        if(i%2==1){
            cout<<i<<' '<<1+f-(i-1)*n-1;
            return 0;
        }
    }
}

}

return 0;
}
