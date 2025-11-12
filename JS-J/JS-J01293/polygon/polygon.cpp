#include"bits/stdc++.h"
using namespace std;
int ans=0;
int n=0;
int a[5005];
vector<vector<int>> us;
bool f(vector <int> sr){
    if(find(us.begin(),us.end(),sr)==us.end()&&us[us.end()-us.begin()]!=sr) return false;
    return true;
}
vector <int>s;
void dfs(int sum,int maxn,int i){
    if(sum>2*maxn&&s.end()-s.begin()+1>2&&!f(s)){
        ans++;
        us.push_back(s);
    }
    if(i==n){
        return ;
    }
    for(int j=i+1;j<=n;j++){
        s.push_back(a[j]);
        dfs(sum+a[j],max(maxn,a[j]),j);
        s.pop_back();
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
