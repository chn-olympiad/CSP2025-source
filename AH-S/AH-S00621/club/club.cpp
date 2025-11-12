#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int tt;
int n;
vector<pair<int,pair<int,int> > > a;
priority_queue<pair<int,int> > b[5];
int t[100000+5][10];
int ans;
bool book[100000+5];
int cnt[10];
int mx(int i){
    int x=t[i][1],y=t[i][2],z=t[i][3];
    int maxx=max({x,y,z});
    if(x==maxx) return 1;
    else if(y==maxx) return 2;
    else return 3;
}
int sec(int i){
    int x=t[i][1],y=t[i][2],z=t[i][3];
    if(x<=y&&x>=z) return 1;
    else if(x<=z&&x>=y) return 1;
    else if(y<=x&&y>=z) return 2;
    else if(y<=z&&y>=x) return 2;
    else if(z<=x&&z>=y) return 3;
    else return 3;
}
void solve(){
    cin>>n;
    a.clear();
    while(b[1].size()) b[1].pop();
    while(b[2].size()) b[2].pop();
    while(b[3].size()) b[3].pop();
    for(int i=1;i<=n;i++) book[i]=false,t[i][1]=t[i][2]=t[i][3]=0;
    cnt[1]=cnt[2]=cnt[3]=0;
    ans=0;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        t[i][1]=x,t[i][2]=y,t[i][3]=z;
        a.push_back(make_pair(i,make_pair(mx(i),sec(i))));
    }
    sort(a.begin(),a.end(),[&](pair<int,pair<int,int> > x,pair<int,pair<int,int> > y){
        return t[x.first][x.second.first]>t[y.first][y.second.first];
    });
    for(int i=0;i<n;i++){
        int node=a[i].first,maxx=mx(node),secc=sec(node);
        if(cnt[maxx]==n/2){
            if(b[maxx].top().first>t[node][secc]-t[node][maxx]){
                ans=ans+t[node][maxx]+b[maxx].top().first;
                cnt[b[maxx].top().second]++;
                b[maxx].pop();
                b[maxx].push(make_pair(t[node][secc]-t[node][maxx],sec(node)));
            }
            else{
                cnt[secc]++;
                ans+=t[node][secc];
            }
        }else{
            cnt[maxx]++;
            ans+=t[node][maxx];
            b[maxx].push(make_pair(t[node][secc]-t[node][maxx],sec(node)));
        }
    }
    cout<<ans<<endl;
    return ;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>tt;
    while(tt--) solve();
    return 0;
}
