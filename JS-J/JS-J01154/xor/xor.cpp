#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first!=y.first)return x.first<y.first;
    return x.second<y.second;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,k;
    cin>>n>>k;
    long long m;
    deque<int> num;
    vector<pair<int,int> > ans;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=0;j<num.size();j++){
            num[j]^=m;
            if(num[j]==k){
                  ans.push_back(make_pair(j+1,i));
            }
        }
        num.push_back(m);
        if(m==k)ans.push_back(make_pair(i,i));
    }
    sort(ans.begin(),ans.end(),cmp);
    int anss=0,pre=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i].first>pre){
            anss++;
            pre=ans[i].second;
        }
    }
    cout<<anss;
    return 0;
}
