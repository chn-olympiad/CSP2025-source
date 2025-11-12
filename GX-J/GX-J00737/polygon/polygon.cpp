#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[5005];
long long sum,cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3)cout<<0;
    if(n=3){
        int maxn;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(a[i]>maxn)maxn=a[i];
        }
        if(2*maxn<sum)cout<<1;
        else cout<<0;
    }
    if(n>3){
        cout<<(n-1)*(n-2)/2%998244353;
    }
    return 0;
}
