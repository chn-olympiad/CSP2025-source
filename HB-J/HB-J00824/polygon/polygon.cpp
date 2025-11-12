#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],ans=0;
bool flag=1;
int C(int n,int m){
    int return_cnt=1;
    for(int i=n;i>n-m;i--)return_cnt*=i;
    for(int i=1;i<=m;i++)return_cnt/=i;
    return return_cnt;
}
void solve1(){
    int sum=0;
    for(int i=3;i<=n;i++){
        sum+=C(n,i);
        sum%=MOD;
    }
    cout<<sum;
}
void dfs(int now,int num,int now_max,int have_choose){
    if(now>n){
        if(num>2*now_max&&have_choose>=3)ans++;
        ans%=MOD;
        return;
    }
    dfs(now+1,num+a[now],max(now_max,a[now]),have_choose+1);
    dfs(now+1,num,now_max,have_choose);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)flag=0;
    }
    if(flag)solve1();
    else{
        dfs(1,0,-1,0);
        cout<<ans%MOD;
    }
    return 0;
}
