#include<bits/stdc++.h>
using ll = long long;
using namespace std;
struct ddd{
    ll x,id;
};
struct node{
    ddd a[3];
}t[100005];
bool cmpp(ddd a,ddd b){
    return a.x>b.x;
}
ll id=-1;
bool cmp(int x,int y){
    return t[x].a[0].x-t[x].a[1].x>t[y].a[0].x-t[y].a[1].x;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            for (int j=0;j<3;j++){
                cin>>t[i].a[j].x;
                t[i].a[j].id=j;
            }
            sort(t[i].a,t[i].a+3,cmpp);
        }
        vector<int> c[3];
        ll ans=0;
        for (int i=1;i<=n;i++){
            c[t[i].a[0].id].push_back(i);
            ans+=t[i].a[0].x;
        }
        ll mx=max({c[0].size(),c[1].size(),c[2].size()});
        // cout<<"***"<<ans<<"\n";
        if(mx<=(n/2)){
            cout<<ans<<"\n";
            continue;
        }
        if(mx==c[0].size()){
            id=0;
        }else if(mx==c[1].size()){
            id=1;
        }else{
            id=2;
        }
        sort(c[id].begin(),c[id].end(),cmp);
        for (int i=mx-1;i>=n/2;i--){
            ans-=t[c[id][i]].a[0].x;
            ans+=t[c[id][i]].a[1].x;
            c[t[c[id][i]].a[1].id].push_back(c[id][i]);
            c[id].pop_back();
            swap(t[c[id][i]].a[0],t[c[id][i]].a[1]);
            swap(t[c[id][i]].a[1],t[c[id][i]].a[2]);
        }
        // cout<<"***"<<ans<<"\n";
        mx=max({c[0].size(),c[1].size(),c[2].size()});
        if(mx<=(n/2)){
            cout<<ans<<"\n";
            continue;
        }
        if(mx==c[0].size()){
            id=0;
        }else if(mx==c[1].size()){
            id=1;
        }else{
            id=2;
        }
        sort(c[id].begin(),c[id].end(),cmp);
        for (int i=mx-1;i>=n/2;i--){
            ans-=t[c[id][i]].a[0].x;
            ans+=t[c[id][i]].a[1].x;
            c[t[c[id][i]].a[1].id].push_back(c[id][i]);
            c[id].pop_back();
            swap(t[c[id][i]].a[0],t[c[id][i]].a[1]);
            swap(t[c[id][i]].a[1],t[c[id][i]].a[2]);
        }
        mx=max({c[0].size(),c[1].size(),c[2].size()});
        if(mx<=(n/2)){
            cout<<ans<<"\n";
            continue;
        }
        if(mx==c[0].size()){
            id=0;
        }else if(mx==c[1].size()){
            id=1;
        }else{
            id=2;
        }
        sort(c[id].begin(),c[id].end(),cmp);
        for (int i=mx-1;i>=n/2;i--){
            ans-=t[c[id][i]].a[0].x;
            ans+=t[c[id][i]].a[1].x;
            c[t[c[id][i]].a[1].id].push_back(c[id][i]);
            c[id].pop_back();
            swap(t[c[id][i]].a[0],t[c[id][i]].a[1]);
            swap(t[c[id][i]].a[1],t[c[id][i]].a[2]);
        }
        mx=max({c[0].size(),c[1].size(),c[2].size()});
        if(mx<=(n/2)){
            cout<<ans<<"\n";
            continue;
        }
        if(mx==c[0].size()){
            id=0;
        }else if(mx==c[1].size()){
            id=1;
        }else{
            id=2;
        }
        sort(c[id].begin(),c[id].end(),cmp);
        for (int i=mx-1;i>=n/2;i--){
            ans-=t[c[id][i]].a[0].x;
            ans+=t[c[id][i]].a[1].x;
            c[t[c[id][i]].a[1].id].push_back(c[id][i]);
            c[id].pop_back();
            swap(t[c[id][i]].a[0],t[c[id][i]].a[1]);
            swap(t[c[id][i]].a[1],t[c[id][i]].a[2]);
        }
        mx=max({c[0].size(),c[1].size(),c[2].size()});
        if(mx<=(n/2)){
            cout<<ans<<"\n";
            continue;
        }
        if(mx==c[0].size()){
            id=0;
        }else if(mx==c[1].size()){
            id=1;
        }else{
            id=2;
        }
        sort(c[id].begin(),c[id].end(),cmp);
        for (int i=mx-1;i>=n/2;i--){
            ans-=t[c[id][i]].a[0].x;
            ans+=t[c[id][i]].a[1].x;
            c[t[c[id][i]].a[1].id].push_back(c[id][i]);
            c[id].pop_back();
            swap(t[c[id][i]].a[0],t[c[id][i]].a[1]);
            swap(t[c[id][i]].a[1],t[c[id][i]].a[2]);
        }
        mx=max({c[0].size(),c[1].size(),c[2].size()});
        if(mx<=(n/2)){
            cout<<ans<<"\n";
            continue;
        }
        if(mx==c[0].size()){
            id=0;
        }else if(mx==c[1].size()){
            id=1;
        }else{
            id=2;
        }
        sort(c[id].begin(),c[id].end(),cmp);
        for (int i=mx-1;i>=n/2;i--){
            ans-=t[c[id][i]].a[0].x;
            ans+=t[c[id][i]].a[1].x;
            c[t[c[id][i]].a[1].id].push_back(c[id][i]);
            c[id].pop_back();
            swap(t[c[id][i]].a[0],t[c[id][i]].a[1]);
            swap(t[c[id][i]].a[1],t[c[id][i]].a[2]);
        }
        mx=max({c[0].size(),c[1].size(),c[2].size()});
        if(mx<=(n/2)){
            cout<<ans<<"\n";
            continue;
        }
    }
    return 0;
}