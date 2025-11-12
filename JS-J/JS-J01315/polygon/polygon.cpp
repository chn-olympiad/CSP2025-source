#include<bits/stdc++.h>
using namespace std;
const long long QM=998244353;
int n,a[5010]={0};
long long ans=0;
vector<int>ly;
void dfs(long long sum,int maxx,int pos){
    if(ly.size()>=3&&sum>2*maxx){
        ans=(ans+1)%QM;
    }
    if(pos>n)return;
    for(int i=pos;i<=n;i++){
        ly.push_back(a[i]);
        dfs(sum+a[i],max(maxx,a[i]),i+1);
        ly.pop_back();
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
