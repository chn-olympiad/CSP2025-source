#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int cnt=0;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);
int b[5010];
for(int i=n-1;i>=0;i--){
    b[n-1-i]=a[i];
}
if(b[0]<b[1]+b[2]){
    cnt++;
}
cout<<cnt;
return 0;
}
