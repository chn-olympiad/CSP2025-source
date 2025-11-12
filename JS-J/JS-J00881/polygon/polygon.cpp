#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[5005];
long long ans;
set<string> s;
bool check(long long sum,int maxn){
    return sum>2*maxn;
}
void dfs(int idx,long long sum,int maxn,string choise){
    if(idx>=3){
        if(check(sum,maxn)){
            s.insert(choise);
        }
    }
    if(idx>n) return ;
    dfs(idx+1,sum+a[idx],a[idx],choise+char(idx+'0'));
    dfs(idx+1,sum,maxn,choise);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,a[1],"");
    cout<<s.size()%mod;
    return 0;
}
