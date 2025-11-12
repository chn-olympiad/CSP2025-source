#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3];
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0),cin>>t;
  while(t--){
    cin>>n;
    int ans=0;
    vector<int>q[3];
    for(int i=1;i<=n;i++){
      cin>>a[i][0]>>a[i][1]>>a[i][2];
      if(a[i][0]>=max(a[i][1],a[i][2]))q[0].push_back(i),ans+=a[i][0];
      else if(a[i][1]>max(a[i][0],a[i][2]))q[1].push_back(i),ans+=a[i][1];
      else q[2].push_back(i),ans+=a[i][2];
    }
    vector<int>t;
    if(q[0].size()>n/2){
      for(int i=0;i<q[0].size();i++)t.push_back(a[q[0][i]][0]-max(a[q[0][i]][1],a[q[0][i]][2]));
      sort(t.begin(),t.end());
      for(int i=0;i<q[0].size()-n/2;i++)ans-=t[i];
    }
    else if(q[1].size()>n/2){
      for(int i=0;i<q[1].size();i++)t.push_back(a[q[1][i]][1]-max(a[q[1][i]][0],a[q[1][i]][2]));
      sort(t.begin(),t.end());
      for(int i=0;i<q[1].size()-n/2;i++)ans-=t[i];
    }
    else if(q[2].size()>n/2){
      for(int i=0;i<q[2].size();i++)t.push_back(a[q[2][i]][2]-max(a[q[2][i]][0],a[q[2][i]][1]));
      sort(t.begin(),t.end());
      for(int i=0;i<q[2].size()-n/2;i++)ans-=t[i];
    }
    cout<<ans<<'\n';
  }
  return 0;
}
