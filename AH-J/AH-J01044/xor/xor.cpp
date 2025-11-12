#include<bits/stdc++.h>
using namespace std;
int a[20000],v[20000];
int n,k,ans=0,f;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++){
        cin>>a[i];
        v[i]=1;
}
f=a[0];
for(int i=0;i<n;i++){
    if(a[i]==k){
        ans++;
        v[i]=0;
    }
}
for(int i=0;i<n;i++){
if(v[i]==0){
        f=a[i+1];
        i++;
}
f^=a[i];
if(f==k){
        ans++;
        f=a[i+1];
        }
}
cout<<ans;
return 0;
}
