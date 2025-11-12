#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long ans,a[5005],b[55];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    b[1]=1;
    for(int i=2;i<=30;i++){b[i]=2*b[i-1];}
    long long x=1<<n;
    long long ans=0;
    for(long long i=6;i<x;i++){
        long long y=i;
        int s1=0,s2=0;
        long long Max=0;
        for(int j=30;j>0;j--){
            if(y>=b[j]){
                Max=max(Max,a[j]);
                s1++;
                s2+=a[j];
                y-=b[j];
            }
            if(y==0)break;
        }
        if(s1>=3&&s2>2*Max){ans++;}
    }
    cout<<ans;
    return 0;
}
