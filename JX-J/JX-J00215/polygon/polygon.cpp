//n<=27 40pts
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
int n,a[5001];
void dfs(int w,vector<int>&v,int maxx,int sum){
    if(v.size()>=3){
        if(sum>2*maxx){
            ans++;
            ans%=998244353;
        }
    }
    if(w==n){
        return;
    }
    for(int i=w+1;i<=n;i++){
        /*if(v.size()>=2&&sum+a[i]>2*max(maxx,a[i])){
            v.push_back(a[i]);
            sum+=a[i];
            dfs(i,v,max(maxx,a[i]),sum);
            sum-=a[i];
            v.pop_back();
        }else if(v.size()<2){*/
            v.push_back(a[i]);
            sum+=a[i];
            dfs(i,v,max(maxx,a[i]),sum);
            sum-=a[i];
            v.pop_back();
        //}
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>v;
    dfs(0,v,0,0);
    cout<<ans;
    return 0;
}