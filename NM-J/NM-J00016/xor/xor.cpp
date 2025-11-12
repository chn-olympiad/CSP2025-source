#include<bits/stdc++.h>
using namespace std;
long long n,s,i,j,x,g,a,b;
int main(){
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     cin>>n>>s;
     for(i=1;i<=n;i++){
        cin>>x;
        if(x==0){
            g=1;
            b++;
        }
        if(x==1){
            a++;
        }
     }
     if(s==0&&g==0){
        cout<<n/2;
        return 0;
     }
     else  if(s==0&&g==1){
        cout<<a/2;
        return 0;
     }
     else if(s==1&&g==1){
        cout<<min(a,b);
     }
     return 0;
}
