#include<bits/stdc++.h>
using namespace std;
#define N 100001
int T,n,ans;
vector<int>u,v,w;
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    u.clear();v.clear();w.clear();ans=0;
    for(int i=1;i<=n;++i){
      int x,y,z;scanf("%d%d%d",&x,&y,&z);
      if(x>=y&&x>=z){
	u.push_back(x-max(y,z));ans+=x;
      }
      else if(y>=x&&y>=z){
	v.push_back(y-max(x,z));ans+=y;
      }
      else{
	w.push_back(z-max(x,y));ans+=z;
      }
    }
    if(u.size()>n/2){
      sort(u.begin(),u.end());
      for(int i=0;i<u.size()-n/2;++i)ans-=u[i];
    }
    if(v.size()>n/2){
      sort(v.begin(),v.end());
      for(int i=0;i<v.size()-n/2;++i)ans-=v[i];
    }
    if(w.size()>n/2){
      sort(w.begin(),w.end());
      for(int i=0;i<w.size()-n/2;++i)ans-=w[i];
    }
    printf("%d\n",ans);
  }
  return 0;
}
