#include<bits/stdc++.h>
using namespace std;
const long long N=998224353;
long long n,ans,cnt=0;
long long a[5005];
bool cmp(long long a,long long b){
    return a<b;
}
void dfs(long long x,long long sum,int len){
    if(len>=3){
        if(sum>a[x]){
            ans++;
        }
    }
    for(int i=x+1;i<=n;i++){
        dfs(i,sum+a[x],len+1);
    }
}
long long jc(long long x,long long y){
    long long cnt=1;
    for(int i=x;i>x-y;i--){
        cnt*=i;
    }
    return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i];
    }
    if(cnt<=n){
        for(int i=1;i<=n;i++){
            ans+=jc(n,i)/jc(i,i);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n-2;i++){
        dfs(i,0,1);
    }
    cout<<ans;
    return 0;
}
