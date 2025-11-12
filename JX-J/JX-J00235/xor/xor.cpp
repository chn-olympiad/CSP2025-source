#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[5*(int)1e5+5];
bool b[5*(int)1e5+5];
bool cmp(pair<int,pair<int,int>>x,pair<int,pair<int,int>>y){
    return x.second.second<y.second.second;
}
bool cmp1(pair<int,pair<int,int>>x,pair<int,pair<int,int>>y){
    if(x.second.second!=y.second.second){
        return x.second.second<y.second.second;
    }
    else{
        return x.second.first < y.second.first;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    vector<pair<long long,pair<long long,long long>>>q;
    for(long long i = 1;i<=n;i++){
        long long now = 0;
        for(long long j = i;j<=n;j++){
            now^=a[j];
            if(now==k){
                q.push_back({i,{j,j-i+1}});
                break;
            }
        }
    }
    sort(q.begin(),q.end(),cmp);
    for(int i = 0;i<q.size();i++){
        int l = q[i].first;
        int r = q[i].second.first;
        bool f = 0;
        for(int j = l;j<=r;j++){
            if(b[j]==1){
                f=1;
                break;
            }
        }
        if(f){
            continue;
        }
        for(int j = l;j<=r;j++){
            b[j]=1;
        }
        ans++;
    }
    cout << ans << '\n';
}
