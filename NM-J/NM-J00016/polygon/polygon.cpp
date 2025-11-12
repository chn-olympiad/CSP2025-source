#include<bits/stdc++.h>
using namespace std;
long long n,s[10000],i;
int main(){
     freopen("polygon.in","r",stdin);
     freopen("polygon.out","w",stdout);
     cin>>n;
     for(i=1;i<=n;i++){
        cin>>s[i];
     }
     if(n==3){
        sort(s+1,s+1+n);
        if(s[1]+s[2]>s[3]){
            cout<<"1";
        }
        else{cout<<"0";}
        return 0;
     }
     return 0;
}
