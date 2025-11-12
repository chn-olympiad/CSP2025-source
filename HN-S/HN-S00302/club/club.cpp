#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,a[N][4],ans,T;
struct node{
    int z,id;
};
vector<node>v[4];
bool cmp(node a,node b){
    return a.z>b.z;
}
void init(){
    ans=0;
    v[1].clear();
    v[2].clear();
    v[3].clear();
    return;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        init();
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                int mx=max(a[i][2],a[i][3]);
                v[1].push_back(node{a[i][1]-mx,i});
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                int mx=max(a[i][1],a[i][3]);
                v[2].push_back(node{a[i][2]-mx,i});
            }
            else{
                int mx=max(a[i][2],a[i][1]);
                v[3].push_back(node{a[i][3]-mx,i});
            }
            ans+=max(a[i][1],max(a[i][2],a[i][3]));
        }
        sort(v[1].begin(),v[1].end(),cmp);
        sort(v[2].begin(),v[2].end(),cmp);
        sort(v[3].begin(),v[3].end(),cmp);
        for(int i=0;i<v[1].size();i++)
            if(i>=n/2) ans-=v[1][i].z;
        for(int i=0;i<v[2].size();i++)
            if(i>=n/2) ans-=v[2][i].z;
        for(int i=0;i<v[3].size();i++)
            if(i>=n/2) ans-=v[3][i].z;
        cout<<ans<<'\n';
    }
    return 0;
}