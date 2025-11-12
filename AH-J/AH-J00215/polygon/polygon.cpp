#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,a[5005],maxn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(n==3){
        sort(a+1,a+4);
        if(a[1]+a[2]>a[3]) cout<<1;
        else               cout<<0;
    }else{
        long long sum=1;
        for(long long i=1;i<=n;i++){
            sum*=2;
            sum%=998244353;
        }
        cout<<((sum+998244353)-n*(n-1)/2-n)%998244353-1;
        return 0;
    }
    fclose(stdin);
    fclose(stdin);
}



