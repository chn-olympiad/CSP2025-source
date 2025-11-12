#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int k,n,a[10000],sum=0;
cin>>n>>k;
for(int i=0;i<n;i++){
cin>>a[i];
}
for(int i=0;i<=n;i++){
if(a[i]==k){
sum++;
}
}
for(int i=0;i<=n;i++){
if(a[i]+=a[i+1]){
sum++;
}
}
fclose(stdin);
fclose(stdout);
return 0;
}

