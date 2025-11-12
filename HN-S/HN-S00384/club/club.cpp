#include<bits/stdc++.h>
using namespace std;
int T;
int A[100005][3];
int n;
struct node{
   int v,w;//变成v，代价为w
   bool friend operator < (const node &a,const node &b){
      return a.w>b.w||a.w==b.w&&a.v<b.v;
   }
};
node diff[100005];
bool cmp(int a,int b){
   return diff[a]<diff[b];
}
void solve(){
   scanf("%d",&n);
   vector<int> D[3];
   for(int i=1;i<=n;i++){
      scanf("%d%d%d",&A[i][0],&A[i][1],&A[i][2]);
      if(A[i][0]>=max(A[i][1],A[i][2])){
         D[0].push_back(i);
      }
      else if(A[i][1]>=max(A[i][0],A[i][2])){
         D[1].push_back(i);
      }
      else if(A[i][2]>=max(A[i][0],A[i][1])){
         D[2].push_back(i);
      }
   }
   int tagi=-1;
   for(int i=0;i<3;i++){
      if(D[i].size()>n/2){
         tagi=i;
         for(int v:D[i]){
            diff[v].w=A[v][i];
            int Max=0,maxi=0;
            for(int j=0;j<3;j++){
               if(i==j)continue;
               if(A[v][j]>=Max){
                  Max=A[v][j];
                  maxi=j;
               }
            }
            diff[v].w-=Max;
            diff[v].v=maxi;
         }
         sort(D[i].begin(),D[i].end(),cmp);
         for(int j=D[i].size()-1;j>=n/2;j--){
            D[diff[D[i][j]].v].push_back(D[i][j]);
            D[i].pop_back();
         }
         break;
      }
   }
   long long ans=0;
   for(int i=0;i<3;i++){
      for(int v:D[i]){
         ans+=A[v][i];
      }
   }
   printf("%lld\n",ans);
   return;;
}
int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   scanf("%d",&T);
   while(T--){
      solve();
   }
   return 0;
}
