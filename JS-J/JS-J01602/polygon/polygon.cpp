#include<bits/stdc++.h>
using namespace std;
const long long N=100000000,mod=998244353;
long long a[N+1],t[N+1];
int main(){
    long long n,tot=1,ans=0;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
         cin>>a[i];
         tot*=2;
    }
    for(int i=0;i<tot;i++){
        long long side=0,pos=0,num=i;
        while(num>0){
            t[pos]=num%2;
            if(num%2==1) side++;
            pos++;
            num/=2;
        }
        long long sum=0,maxn=0;
        if(side>=3){
            for(int j=0;j<n;j++){
                if(t[j]==1){
                    maxn=max(maxn,a[j]);
                    sum+=a[j];
                }
            }
            if(maxn*2<sum) ans=(ans+1)%mod;
        }
    }
    cout<<ans;
    return 0;
}
