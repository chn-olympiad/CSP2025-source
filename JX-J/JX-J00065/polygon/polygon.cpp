#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
vector<long long> xx;
map<vector<long long>,int> bb;
void dfs(long long x,long long cnt,long long maxx,long long cntt,vector<long long> xxx){
    if(cnt>2*maxx&&cntt>2&&bb[xxx]==0) {
        ans++;
        ans%=998244353;
        bb[xxx]++;
    }
    if(x==n) return ;
    dfs(x+1,cnt,maxx,cntt,xxx);
    xxx.push_back(a[x+1]);
    dfs(x+1,cnt+a[x+1],max(maxx,a[x+1]),cntt+1,xxx);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,a[0],a[0],0,xx);
    cout<<ans<<endl;
    return 0;
}
