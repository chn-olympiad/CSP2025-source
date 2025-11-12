#include<bits/stdc++.h>
// #define int long long
using namespace std;

int t,n;

struct node{
  int val[4];
  int dmx1,dmx2;
  bool operator < (const node &h){
    int mx1=max(val[1],val[2]);
    int mx2=max(h.val[1],h.val[2]);
    int mn1=min(val[1],val[2]);
    int mn2=min(h.val[1],h.val[2]);
    return mx1-mn1>mx2-mn2;
    if(mx1-mn1==mx2-mn2){
      return mx1>mx2;
    }
  }
}a[100001];

int cnt[4],ans;

void dfs(int x,int val){
  if(x>n){
    if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
      ans=max(ans,val);
    }
    return;
  }
  for(int i=1;i<=3;i++){
    cnt[i]++;
    dfs(x+1,val+a[x].val[i]);
    cnt[i]--;
  }
  // cout<<x<<'\n';
}

signed main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>t;

  while(t--){
    cin>>n;
    memset(cnt,0,sizeof cnt);
    if(n>10){
      ans=0;
      for(int i=1;i<=n;i++){
        cin>>a[i].val[1]>>a[i].val[2]>>a[i].val[3];
      }
      sort(a+1,a+n+1);

      for(int i=1;i<=n;i++){
        int mx=max(a[i].val[1],a[i].val[2]);
        int mn=min(a[i].val[1],a[i].val[2]);

        int px=-1,pn=-1;

        for(int j=1;j<=2;j++){
          if(a[i].val[j]==mx && px==-1){
            px=j;
          }
          else if(a[i].val[j]==mn && pn==-1){
            pn=j;
          }
        }

        if(cnt[px]<n/2){
          cnt[px]++;
          ans+=mx;
        }
        else if(cnt[pn]<n/2){
          cnt[pn]++;
          ans+=mn;
        }

      }

      cout<<ans<<'\n';

      continue;
    }
    for(int i=1;i<=n;i++){
      cin>>a[i].val[1]>>a[i].val[2]>>a[i].val[3];
    }
    dfs(1,0);
    cout<<ans<<'\n';
    ans=0;
  }

}