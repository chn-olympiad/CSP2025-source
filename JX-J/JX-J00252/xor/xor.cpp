#include<bits/stdc++.h>
using namespace std;
long long a[500001]={};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,w,ma=1,s=1;
    cin>>n>>w;
   for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1){
            if(a[i]==a[i-1]){
                s++;
                if(s>ma){
                    ma=s;
                }
            }
            else{
                s=1;
            }
        }
   }
   cout<<ma;
    return 0;
}

