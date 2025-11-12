#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long cnt=0;
long long mod=998244353;
int sum=0;
int maxn=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        maxn=max(a[i],maxn);
    }
    if(n<=3){
       if(n<=2){
        cout<<0;
        return 0;
       }
       if(n==3){
         if(sum>2*maxn){
            cout<<1;
         }
         else{
            cout<<0;
         }
         return 0;
       }
    }
    else{
        for(int m=0;m<n;m++){
            int miax=-1e9;
            for(int i=1;i<=n-2;i++){
                miax=max(miax,a[i]);
                for(int j=i+1;j<=n-1;j++){
                    miax=max(miax,a[j]);
                    int to=a[i]+a[j];
                    for(int k=j+1;k<=j+1+m;k++){
                        to+=a[k];
                        miax=max(miax,a[k]);
                        if(to>(miax*2)){
                            cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
