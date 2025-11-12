#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > nums;
vector<vector<int> > f;
vector<pair<int,int> > lr;
bool cmd(pair<int,int> a,pair<int,int> b){
    return abs(a.second-a.first)<abs(b.second-b.first);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        vector<int> t(1);
        cin>>t[0];
        while(t[0]>=2){
            t.insert(t.begin(),0);
            t[0]+=t[1]/2;
            t[1]%=2;
        }
        while(t.size()<8) t.insert(t.begin(),0);
        nums.push_back(t);
    }
    vector<int> t(8,0);
    for(int i=0;i<n;i++){
        f.push_back(t);
        for(int j=0;j<8;j++){
            t[j]+=nums[i][j];
            t[j]%=2;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            vector<int> sum(8);
            for(int k=0;k<8;k++) sum[k]=f[i][k]^f[j][k]^nums[j][k];
            int num=0;
            for(int k=7;k>=0;k--) num+=sum[k]*pow(2,7-k);
            if(num==m) lr.push_back(make_pair(i,j));
        }
    }
    sort(lr.begin(),lr.end(),cmd);
    vector<bool> used(n,0);
    for(int i=0;i<lr.size();i++){
        for(int j=lr[i].first;j<=lr[i].second;j++){
            if(used[j]){
                cout<<i;
                return 0;
            }
            used[j]=1;
        }
    }
    cout<<lr.size();
    return 0;
}
