#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+5;
struct node{
	int a[4],c;
}a[N];
int cnt[N];
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.first>y.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				scanf("%d",&a[i].a[j]);
				a[i].c=0;
			}
			a[i].c=a[i].a[1]>a[i].a[2]?(a[i].a[1]>a[i].a[3]?1:3):(a[i].a[2]>a[i].a[3]?2:3);
			cnt[a[i].c]++;
		}
		long long ans=0;
		for(int j=1;j<=3;++j)
			if(cnt[j]>n/2){
				vector<pair<int,int>>v;
				int t1=j+1,t2=j+2;
				if(t1>3)t1-=3;
				if(t2>3)t2-=3;
				for(int i=1;i<=n;++i)
					if(a[i].c==j)
						v.push_back({max(a[i].a[t1]-a[i].a[j],a[i].a[t2]-a[i].a[j]),i});
				sort(v.begin(),v.end(),cmp);
				for(int i=0;i<cnt[j]-n/2;++i){
					ans+=a[v[i].second].a[j]+v[i].first;
					a[v[i].second].c=0;
				}
				break;
			}
		for(int i=1;i<=n;++i)
			if(a[i].c)
				ans+=a[i].a[a[i].c];
		printf("%lld\n",ans);
	}
	return 0;
}
