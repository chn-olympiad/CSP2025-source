#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
vector<int> tmp;
struct node{
    int d,maxx,id;
};
vector<node> c;
bool cmp(node x,node y){
    if(x.d==y.d) return x.maxx>y.maxx;
    return x.d>y.d;
}
int n,m;
int v[100005];
int fans=0;
void dfs(int cur,int x,int y,int z){
    if(cur>n){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=a[i][v[i]];
        }
        fans=max(fans,ans);
        return ;
    }
    v[cur]=1;
    if(x<n/2) dfs(cur+1,x+1,y,z);
    v[cur]=2;
    if(y<n/2) dfs(cur+1,x,y+1,z);
    v[cur]=3;
    if(z<n/2) dfs(cur+1,x,y,z+1);
}
void solve(){
    tmp.clear();
    c.clear();
    fans=0;
    memset(v,0,sizeof(v));
    cin>>n;
    int f1=1,f2=1;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(a[i][2]!=0){
            f1=0;
        }
        if(a[i][3]!=0){
            f2=0;
        }
    }
    if(f1==1&&f2==1){
        for(int i=1;i<=n;i++){
            tmp.push_back(a[i][1]);
        }
        sort(tmp.begin(),tmp.end(),greater<int>());
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans+=tmp[i];
        }
        cout<<ans<<endl;
        return ;
    }else if(f2==1){
        for(int i=1;i<=n;i++){
            c.push_back({max(a[i][1],a[i][2])-min(a[i][1],a[i][2]),max(a[i][1],a[i][2]),i});
        }
        sort(c.begin(),c.end(),cmp);
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans+=max(a[c[i].id][1],a[c[i].id][2]);
        }
        for(int i=n/2;i<n;i++){
            ans+=min(a[c[i].id][1],a[c[i].id][2]);
        }
        cout<<ans<<endl;
        return ;
    }else{
        //cout<<"jigr";
        dfs(1,0,0,0);
        cout<<fans<<endl;
    }
}
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
