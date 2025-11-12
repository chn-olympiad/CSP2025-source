#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010];
int s[500010],ans,last;
vector<pair<int,int> > v;
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((s[j]^s[i-1])==k){
                v.push_back(make_pair(i,j));
                break;
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if(i==0){
            ans++;
            last=v[i].second;
        }
        else{
            if(v[i].first>last){
                ans++;
                last=v[i].second;
            }
        }
    }
    cout<<ans;
    return 0;
}