#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
long long n,k,a[500001],ans=0;
bool pai(long long x,long long d){
    if(x>n){
        ans=max(ans,d-1);
        return true;
    }
    long long cnt=0;
    for (int i=x;i<=n;i++){
        cnt=(cnt^a[i]);
        if(cnt==k and pai(i+1,d+1)){
            // cout<<d<<":"<<x<<"~"<<i<<"!"<<endl;
            return true;
        }
    }
    return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    pai(1,1);
    cout<<ans;
    return 0;
}