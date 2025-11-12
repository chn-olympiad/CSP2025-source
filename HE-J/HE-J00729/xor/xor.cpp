#include<bits/stdc++.h>
using namespace std;
int aaa(int gcid[],int n,int m){
    if(n==m+1){
            return 0;
    }else{
return gcid[n]|aaa(gcid,n+1,m);
    }
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int length,k;
int gcid[length];
cin>>length>>k;
for(int i=0;i<length;i++){
    cin>>gcid[i];
}
int ans=0;
int n=0,m=0;
for(n;n<length;n++){
for(m=n;m<length;m++){
    if(aaa(gcid,n,m)==k){
        ans++;
        n++;


    }
}
}
if(gcid[0]==k){
ans++;
}
cout<<ans;

return 0;
}
