#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long m=0,n=0,a=1,ans=1;
char ca[10000];
long long aa[100000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>m>>n;
    for(int i=0;i!=m;i++){
        cin>>ca[i];
        if(ca[i]!='1'){
            a=0;
        }
    }
    for(int i=0;i!=m;i++){
        cin>>aa[i];
    }
    if(a==1){
        for(int j=1;j!=m+1;j++){
            ans*=j;
            if(ans%998==0){
                ans/=998;
            }
            if(ans%244==0){
                ans/=244;
            }
            if(ans%353==0){
                ans/=353;
            }
        }
    }
    cout<<ans;
    return 0;
}
