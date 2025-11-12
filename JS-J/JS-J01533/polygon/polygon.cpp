#include<bits/stdc++.h>
using namespace std;
int a[10005];
long long ans=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);//.out!!!
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<=n-3;++i){
        for(int j=i+1;j<=n-2;++j){
            for(int k=j+1;k<=n-1;++k){
                if(!(a[j]+a[k]>a[i])){
                    j=n;break;
                }else{

                    if(ans>=998244353)ans%=998244353;
                    ans+=n-k;
                }
            }
        }
    }
    cout<<ans%998244353<<"\n";
    return 0;
}
