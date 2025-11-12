#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,t,cnt=0;
//vector<vector<int>> dp;
bool dfs(int nt,int t,vector<int> a){
    if(t==nt){
        int ma=a[0],sum=a[0];
        for(int i=1;i<a.size();i++){
            sum+=a[i];
            if(a[i]>ma)ma=a[i];
        }
        if(sum>2*ma)return true;
        else return false;
    }
    for(int i=0;i<n;i++){
        a.push_back(v[i]);
        bool f=dfs(nt,t+1,a);
        a.pop_back();
        if(f)cnt=(cnt+1)%998244353;
        else return false;
    }
}
int main(){
    //dp.resize(5010);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    vector<int> ch;
    for(int i=3;i<=n;i++){
        dfs(i,0,ch);
    }
    cout<<cnt;
}
