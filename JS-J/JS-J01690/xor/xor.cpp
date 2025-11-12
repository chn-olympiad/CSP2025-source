#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int n,k;
vector<pair<int,int>> v;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=i;j<=n;j++){
            x=x^a[j];
            if(x==k) v.push_back({i,j});
        }
    }
    sort(v.begin(),v.end(),cmp);
    int ans=0;
    int start=1;
    for(int i=0;i<v.size();i++){
        if(v[i].first>=start){
            ans++;
            start=v[i].second+1;
        }
    }
    cout<<ans;
    return 0;
}
