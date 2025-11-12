#include<bits/stdc++.h>
using namespace std;
int n,a[10000000],e=0;
int cmp(int a,int b){
return a<b;
}
int main(){
    freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n-2;i++){
    for(int j=j+1;j<=n-1;j++){
    for(int k=k+1;k<=n;k++){
    if(a[i]+a[j]+a[k]>2*a[k])e++;
    }}}cout<<e/3;
    return 0;
}
