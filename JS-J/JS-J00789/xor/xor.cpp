#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdio>
#define N 500005
using namespace std;
long long a[N];
int n;
long long k;
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
}
map<long long,vector<int> >mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    a[0]=0;
    vector<pair<int,int> > v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
        mp[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((a[i-1]^a[j])==k)v.push_back(make_pair(i,j));
        }
    }/*
    for(int i=1;i<=n;i++){
        int mn=10000000;
        for(int j=mp[a[i-1]^k].size()-1;j>=0;j--){
            if(mp[a[i-1]^k][j]>=i)mn=min(mn,mp[a[i-1]^k][j]);
        }
        v.push_back(make_pair(i,mn));
    }*/
    sort(v.begin(),v.end(),cmp);
    //for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;
    int ed=0;
    long long cnt=0;
    for(int i=0;i<v.size();i++){
        if(ed<v[i].first){
            ed=v[i].second;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
