#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n;
struct student{
  int cluba;
  int clubb;
  int clubc;
}students[N];
int ans = 0;
void search(int now,int ca,int cb,int cc,int tot){
  if(ca>n/2||cb>n/2||cc>n/2){
    return ;
  }
  if(now==n){
    ans = max(ans,tot);
    return;
  }
search(now+1,ca+1,cb,cc,tot+students[now].cluba);
search(now+1,ca,cb+1,cc,tot+students[now].clubb);
search(now+1,ca,cb,cc+1,tot+students[now].clubc);
}
  bool cmp(student a,student b){
    return a.cluba>b.cluba;
  }
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int t;
  cin>>t;
  while(t--){
    ans=0;
    cin>>n;
    bool suba=true;
    for(int i = 0;i<n;i++){
      int a,b,c;
      cin>>a>>b>>c;
      if(b!=0||c!=0){
	suba=false;
      }
      students[i].cluba = a;
      students[i].clubb = b;
      students[i].clubc = c;
    }
    if(suba){
      sort(students,students+n,cmp);
      for(int i = 0;i<n/2;i++){
	ans+=students[i].cluba;
      }
      cout<<ans<<endl;
      continue;
    }
    search(0,0,0,0,0);
    cout<<ans<<endl;
  }
  return 0;
}
