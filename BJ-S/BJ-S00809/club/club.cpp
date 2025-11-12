#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{int x,y,z;}a[100005];
set<pair<int,int>> p,q,r;
vector<int> v;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n,ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x)p.insert({a[i].x,i});
            else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y)q.insert({a[i].y,i});
            else r.insert({a[i].z,i});
        }
        for(auto k:p)ans+=k.first;
        for(auto k:q)ans+=k.first;
        for(auto k:r)ans+=k.first;
        v.clear();
        if(p.size()>n/2){
            for(auto k:p)v.push_back(k.first-max(a[k.second].y,a[k.second].z));
            sort(v.begin(),v.end());
            for(int i=0;i<p.size()-n/2;i++)ans-=v[i];
        }
        if(q.size()>n/2){
            for(auto k:q)v.push_back(k.first-max(a[k.second].x,a[k.second].z));
            sort(v.begin(),v.end());
            for(int i=0;i<q.size()-n/2;i++)ans-=v[i];
        }
        if(r.size()>n/2){
            for(auto k:r)v.push_back(k.first-max(a[k.second].x,a[k.second].y));
            sort(v.begin(),v.end());
            for(int i=0;i<r.size()-n/2;i++)ans-=v[i];
        }
        while(!p.empty())p.erase(p.begin());
        while(!q.empty())q.erase(q.begin());
        while(!r.empty())r.erase(r.begin());
        cout<<ans<<"\n";
    }
}