#include<bits/stdc++.h>
using namespace std;
struct node {
  int v1,cnt1,v2,cnt2;
  _Bool operator<(const node other) const{
    return v1+other.v2<v2+other.v1;
  }
};
int T,n,ans;
vector<pair<int,int> > a[200005];
priority_queue<node> q;
int cnt[3];
int main() {
  freopen("club.in","r",stdin);
  freopen("club.out","w+",stdout);
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&n);
    ans=0;
    for(int i=1;i<=n;i++) {
      a[i].resize(3);
      scanf("%d %d %d",&a[i][0].first,&a[i][1].first,&a[i][2].first);
      a[i][0].second=0; a[i][1].second=1; a[i][2].second=2;
      sort(a[i].begin(),a[i].end(),greater<pair<int,int> >());
      q.push((node){a[i][0].first,a[i][0].second,a[i][1].first,a[i][1].second});
	}
	cnt[0]=cnt[1]=cnt[2]=0;
    while(q.size()) {
      node u=q.top();
      q.pop();
      if(cnt[u.cnt1]<n>>1) {
        ans+=u.v1;
        cnt[u.cnt1]++;
	  }
	  else {
	    ans+=u.v2;
	    cnt[u.cnt2]++;
	  }
	}
	printf("%d\n",ans);
  }
}

