#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long c(long long x,long long y){
    long long s1=1;
    long long s2=1;
    long long yy=y;
    long long xx=x;
    for(int i=0;i<y;i++){
        s1*=(xx--);
    }
    while(yy!=0){
        s2*=(yy--);
    }
    return s1/s2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    long long sum=0;
    long long maxn=INT_MIN;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(n==3){
        if(sum>2*maxn){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
            long long ans=0;
            for(int i=3;i<=n;i++){
                ans+=c(n,i);
            }
    cout<<ans;
    }
    return 0;
}

