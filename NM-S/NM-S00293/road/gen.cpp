#include<iostream>
#include<algorithm>
#include<random>
std::mt19937 rnd(std::random_device{}());
int main(){
  freopen("road.in","w",stdout);
  int n=1e4,m=1e6,k=10;
  std::cout<<n<<" "<<m<<" "<<k<<"\n";
  for(int i=1;i<=m;i++){
    int u=rnd()%n+1,v=rnd()%n+1,w=rnd()%1000000000+1;
    while(u==v)u=rnd()%n+1,v=rnd()%n+1;
    std::cout<<u<<" "<<v<<" "<<w<<"\n";
  }
  for(int i=1;i<=k;i++){
    for(int i=1;i<=n+1;i++)std::cout<<rnd()%1000000000+1<<" ";
    std::cout<<"\n";
  }
  return 0;
}