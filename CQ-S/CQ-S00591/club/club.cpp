#include<bits/stdc++.h>
using namespace std;
int n,a[100010][3],op[100010];
void solve(){
   scanf("%d",&n);
   int ans=0,cnt[3]{};
   for(int i=1;i<=n;i++){
      scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
      int w=max({a[i][0],a[i][1],a[i][2]});
      for(int o:{0,1,2}){
         if(a[i][o]==w){
            ans+=w,op[i]=o,cnt[o]++;break;
         }
      }
   }
   int p=-1;
   for(int o:{0,1,2})if(cnt[o]>n/2)p=o;
   if(p==-1)return printf("%d\n",ans),void();
   vector<int>vals;
   for(int i=1;i<=n;i++)if(op[i]==p){
      int w=-1e9;
      for(int x:{0,1,2})if(x!=p)w=max(w,a[i][x]-a[i][p]);
      vals.push_back(w);
   }
   sort(begin(vals),end(vals),greater<>{});
   int res=cnt[p]-n/2;
   for(int i=0;i<res;i++)ans+=vals[i];
   printf("%d\n",ans);
}
int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   int T;for(scanf("%d",&T);T--;)solve();
   return 0;
}