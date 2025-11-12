#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5009];
long long ans[5009][2];
queue<pair<long long,int>>q;
long long pt(int i){
    long long num=0;
    queue<pair<long long,int>>q1=q;
    while(q1.size()){
        int sum=q1.front().first,large=q1.front().second;
        q1.pop();
        if(a[i]+sum>large)num++;
        else q.push({a[i]+sum,large});
    }for(int j=n;j>i;j--)
        q.push({a[i],a[j]});
    return num%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n;i;i--){
        ans[i][1]=ans[i][0]=(ans[i+1][0]+ans[i+1][1])%mod;
        ans[i][1]=(ans[i][1]+pt(i))%mod;
    }cout<<(ans[1][1]+ans[1][0])%mod;
}
