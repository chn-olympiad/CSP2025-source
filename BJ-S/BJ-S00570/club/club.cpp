#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,b[N][5];
bool subA(){
    for(int i=1;i<=n;i++){
        if(b[i][2]||b[i][3])return 0;
    }return 1;
}
void dfs(int x,int ca,int cb,int cc,int sum){
    if(ca>n/2||cb>n/2||cc>n/2)return;
    if(x==n){
        ans=max(ans,sum);
        return;
    }
    dfs(x+1,ca+1,cb,cc,sum+b[x+1][1]);
    dfs(x+1,ca,cb+1,cc,sum+b[x+1][2]);
    dfs(x+1,ca,cb,cc+1,sum+b[x+1][3]);
}
struct node{
    int x,id;
    friend bool operator<(node x,node y){return x.x>y.x;}
};
vector<node>a[N];
priority_queue<node>q[5];
void get(int i){
    if(a[i].empty())return;
    int mxi=a[i][0].id;
    q[a[i][0].id].push({a[i][0].x,i});
    a[i].erase(a[i].begin());
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>b[i][1]>>b[i][2]>>b[i][3];
        }
        ans=0;
        if(n<=30)dfs(0,0,0,0,0);
        else if(subA()){
            vector<int>x;
            for(int i=1;i<=n;i++){
                x.emplace_back(b[i][1]);
            }sort(x.begin(),x.end(),greater<>());
            for(int i=0;i<n/2;i++){
                ans+=x[i];
            }
        }else{
            for(int i=1,x,y,z;i<=n;i++){
                x=b[i][1],y=b[i][2],z=b[i][3];
                a[i].push_back({x,1});
                a[i].push_back({y,2});
                a[i].push_back({z,3});
                sort(a[i].begin(),a[i].end());
            }
            for(int i=1;i<=n;i++){
                get(i);
                for(int j=1;j<=3;j++)while(q[j].size()>n/2){
                    int cur=q[j].top().id;q[j].pop();
                    get(cur);
                }
            }ans=0;
            for(int j=1;j<=3;j++){
                while(q[j].size()){
                    ans+=q[j].top().x;
                    cout<<j<<" "<<q[j].top().x<<'\n';
                    q[j].pop();
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}