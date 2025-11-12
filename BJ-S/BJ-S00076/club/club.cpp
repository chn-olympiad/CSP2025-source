#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n;
struct iint{
    pair<int,int> w[3];
}a[N];

bool cmp(iint x,iint y){
    return (x.w[1].second-x.w[2].second)>(y.w[1].second-y.w[2].second);
}
bool cmp1(pair<int ,int> x,pair<int ,int> y){
    return x.second>y.second;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
      cin>>n;
      int ans=0;
      for(int i=1;i<=n;i++){
        cin>>a[i].w[1].second>>a[i].w[2].second>>a[i].w[3].second;
        a[i].w[1].first=1;
        a[i].w[2].first=2;
        a[i].w[3].first=3;
        sort(a[i].w+1,a[i].w+4,cmp1);
      }
      sort(a+1,a+n+1,cmp);
      int s[4]={0};
      for(int i=1;i<=n;i++){
        int pos1=a[i].w[1].first,pos2=a[i].w[2].first;
        if(s[pos1]<n/2){
            s[pos1]++;
            ans+=a[i].w[1].second;
        }
        else{
            s[pos2]++;
            ans+=a[i].w[2].second;
        }

      }
      cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

