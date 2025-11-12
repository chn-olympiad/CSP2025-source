#include<bits/stdc++.h>
using namespace std;
int a[5006];
int main(){
int n,m=1,ans=0;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]>m){
        m=a[i];
    }
}
if(m==1){
    for(int i=1;i<=n-2;i++){
        for(int j=1;j<=i;j++){
            ans+=j;
        }
    }
}
return 0;
}
