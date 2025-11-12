#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN(5005);
const int MOD(998244353);
int n,ans;
int a[MAXN];
int d;

void dfs(int sum,int maxsum,int beishu,int num,int b){
    bool f=true;
    if(sum>maxsum*2&&b>=3){
        ans=(ans+(beishu%MOD))%MOD;
        f=false;
    }
    if(num>n){
        return;
    }
    int res=upper_bound(a+1,a+n+1,a[num])-lower_bound(a+1,a+n+1,a[num]);
    int cnt=upper_bound(a+1,a+n+1,a[num])-a;
    dfs(sum+a[num],max(maxsum,a[num]),beishu*res%MOD,cnt,b+1);
    if(f)
    dfs(sum,maxsum,beishu,cnt,b);
    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(0,0,1,1,0);
    cout<<ans;
    return 0;
}
