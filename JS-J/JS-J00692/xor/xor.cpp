#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],ans,sum,lei=INT_MAX;
int work(int x,int num){
    sum=a[x];
    for(int i=x+1;i<=n;i++){
        sum^=a[i];
        if(sum==k){
            lei=min(lei,i+1);
            work(i+1,num+1);
        }
    }
    return num;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1];
    ans=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(i>=lei)break;
        ans=max(ans,work(i,0));
    }
    cout<<ans;
    return 0;
}
