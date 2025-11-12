// shinzanmonoWYB@hs2z
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
const int sz=1e5+10;
const int inf=0x3fffffff;
int a[sz][3],c[sz][3];
void file(std::string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
std::priority_queue<int>sum[3];
int main(){
  file("club");
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin>>t;
  while(t--){
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)std::cin>>a[i][0]>>a[i][1]>>a[i][2];
    while(!sum[0].empty())sum[0].pop();
    while(!sum[1].empty())sum[1].pop();
    while(!sum[2].empty())sum[2].pop();
    int ans=0;
    for(int i=1;i<=n;i++){
      std::vector<std::pair<int,int>>A;
      for(int j:{0,1,2})A.emplace_back(a[i][j],j);
      std::sort(A.begin(),A.end(),std::greater<>());
      sum[A[0].second].push(A[1].first-A[0].first),ans+=A[0].first;
    }
    while(sum[0].size()>n/2)ans+=sum[0].top(),sum[0].pop();
    while(sum[1].size()>n/2)ans+=sum[1].top(),sum[1].pop();
    while(sum[2].size()>n/2)ans+=sum[2].top(),sum[2].pop();
    std::cout<<ans<<"\n";
  }
  return 0;
}