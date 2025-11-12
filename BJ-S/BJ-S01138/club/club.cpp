#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100009][5];
int n;
vector<array<int,3>> vec[4];
int cnt[5];
inline bool cmp(pair<int,int> x,pair<int,int> y){return x.first<y.first;}
inline void solve(){
cin>>n;
int ans=0;
memset(cnt,0,sizeof cnt);
for(int i=1;i<=3;i++)vec[i].clear();
for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
for(int i=1;i<=n;i++){
    if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])vec[1].push_back({a[i][1],a[i][2],a[i][3]}),ans+=a[i][1],cnt[1]++;
    else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])vec[2].push_back({a[i][1],a[i][2],a[i][3]}),ans+=a[i][2],cnt[2]++;
    else ans+=a[i][3],vec[3].push_back({a[i][1],a[i][2],a[i][3]}),cnt[3]++;
}
//cout<<ans<<endl;
vector<pair<int,int>> tmp;
vector<int> c;
for(int i=1;i<=3;i++){
    //cout<<vec[i].size()<<" "<<cnt[i]<<endl;
    if(cnt[i]>n/2){
           for(int j=0;j<vec[i].size();j++)c.push_back(vec[i][j][i-1]),vec[i][j][i-1]=-1,tmp.push_back({c[j]-max({vec[i][j][0],vec[i][j][1],vec[i][j][2]}),j});
           sort(tmp.begin(),tmp.end(),cmp);
          int l=0;
           while(cnt[i]>n/2){

            cnt[i]--;
       ans-=tmp[l].first;
        l++;
           }
        break;
    }
}
cout<<ans<<endl;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--)solve();

return 0;

}
