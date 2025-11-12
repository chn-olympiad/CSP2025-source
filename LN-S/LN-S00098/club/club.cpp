#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
struct node{
  int a,b,c;
}p[N];
pair<int,int> b[N];
int vb,vc;
int n,m,ans;
string s;
signed main(){
   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //next_permutation()
    int t;
    cin>>t;
    while(t--){
  ans=0;
  vb=vc=0;
  cin>>n;
  for(int i=1;i<=n;i++) {
        cin>>p[i].a>>p[i].b>>p[i].c;
        int x=p[i].c-p[i].a;
        int y=p[i].b-p[i].a;
        b[i].first=y;
        b[i].second=x;
        ans+=p[i].a;
  }
  //cout<<ans<<endl;
  sort(b+1,b+n+1,greater<pair<int,int> >());
  for(int i=1;i<=n/2;i++){
   if(b[i].first>=b[i].second){
    ans+=b[i].first;
    vb++;
   }
   if(b[i].first<b[i].second){
    ans+=b[i].second;
    vc++;
   }
  }
for(int i=n/2+1;i<=n;i++){
   if(b[i].first>=b[i].second&&vb<n/2){
        int ans1=ans;
    ans+=max(b[i].first,0ll);
    if(ans1!=ans) vb++;
   }
   else if(vc<n/2){
       int ans1=ans;
    ans+=max(b[i].second,0ll);
    if(ans1!=ans) vc++;
   }
  }
  cout<<ans<<endl;
  }
return 0;
}
