#include<bits/stdc++.h>
using namespace std;
struct node{
	int s[3];
}a[100005];
int bl[100005],n;
vector<int>v[3];
inline void solve()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].s[0],&a[i].s[1],&a[i].s[2]);
		if(a[i].s[0]>a[i].s[1]&&a[i].s[0]>a[i].s[2])ans+=a[i].s[0],bl[i]=0;
		else if(a[i].s[1]>a[i].s[0]&&a[i].s[1]>a[i].s[2])ans+=a[i].s[1],bl[i]=1;
		else ans+=a[i].s[2],bl[i]=2;
	}
	for(int i=1;i<=n;++i){
		v[bl[i]].push_back(max(a[i].s[(bl[i]+1)%3],a[i].s[(bl[i]+2)%3])-a[i].s[bl[i]]);
	}
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	sort(v[2].begin(),v[2].end());
	for(int i=0;i<3;++i){
		while((int)(v[i].size())>(n/2))ans+=v[i].back(),v[i].pop_back();
	}
	printf("%d\n",ans);
	v[0].clear(),v[1].clear(),v[2].clear();
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
