#include<bits/stdc++.h>
using namespace std;
long long a[10000],n,m=1;
bool b[10000];
long long f(long long c){
    long long ans=0,i,j,d,e;
    for(i=m;i<=n;i+=1){
        b[i]=1;
        m=i+1;
        if(c>=3){
            d=0;
            e=0;
            for(j=1;j<=n;j+=1){
                if(b[j]){
                    d+=a[j];
                    e=max(e,a[j]);
                }
            }
            d-=e;
            if(d>e){
                ans+=1;
            }
        }
        ans+=f(c+1);
        ans%=998244353;
        b[i]=0;
        m=i+1;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long i;
    cin>>n;
    for(i=1;i<=n;i+=1){
        cin>>a[i];
    }
    cout<<f(1);
    return 0;
}
