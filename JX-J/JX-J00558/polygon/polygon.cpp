#include<bits/stdc++.h>
using namespace std;
long long a[5005],cnt=0;
const long long N=998244353;
int n;
void dfs(int len,int pre,int i,long long maxs,long long sum){
    //cout<<cnt<<" ";
    if (len>=3&&pre!=len){
            //if(sum>(maxs*2)?1LL:0LL)cout<<len<<" "<<i<<" "<<maxs<<" "<<sum<<endl;
            cnt=(cnt+(sum>(maxs*2)?1LL:0LL))%N;
    }
    if (i>=n)return;

    dfs(len+1,len,i+1,max(maxs,a[i+1]),sum+a[i+1]);
    dfs(len,len,i+1,maxs,sum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    //cout<<n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    dfs(0,0,0,0,0);
    cout<<cnt;
    return 0;
}
