#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500010];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>a[i];
}
if(k=0){
    cout<<n;
}else{
cout<<1;
}
return 0;
}
