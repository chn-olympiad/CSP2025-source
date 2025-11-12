#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
int n,k,b=0,c=0,ans=0;
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==1) b++;
    if(a[i]!=0&&a[i]!=1) c++;
}
if(b==n){
    cout<<n/2;
}
if(c==0){
    if(k==0){
       for(int i=1;i<=n;i++){
            if(a[i]==0){
                    ans++;
            } else{
            if(a[i+1]==1) {
                i++; ans++;
            }
            }
        }
        cout<<ans;
    }else{
    for(int i=1;i<=n;i++){
            if(a[i]==1){
                    ans++;
            }
        }
    }
}
return 0;
}

