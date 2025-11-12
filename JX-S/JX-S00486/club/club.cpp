#include<bits/stdc++.h>
using namespace std;
int t,n,d[4],ans;
struct cy{
	pair<int,int> d[4];
}a[100005];
bool cmp(cy x,cy y){
	if(x.d[1].first==y.d[1].first){
		if(x.d[2].first==y.d[2].first){
			return x.d[3].first>y.d[3].first;
		}
		return x.d[2].first>y.d[2].first;
	}
	return x.d[1].first>y.d[1].first;
}
bool cmpp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].d[1].first,&a[i].d[2].first,&a[i].d[3].first);
			a[i].d[1].second=1;
			a[i].d[2].second=2;
			a[i].d[3].second=3;
			if(a[i].d[1].first>a[i].d[2].first){
				swap(a[i].d[1],a[i].d[2]);
			}
			if(a[i].d[2].first>a[i].d[3].first){
				swap(a[i].d[2],a[i].d[3]);
			}
			if(a[i].d[3].first>a[i].d[1].first){
				swap(a[i].d[3],a[i].d[1]);
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<4;j++){
				if(d[a[i].d[j].second]==n/2) continue;
				d[a[i].d[j].second]++;
				ans+=a[i].d[j].first;
				break;
			}
		} 
		printf("%d\n",ans);
		d[1]=d[2]=d[3]=ans=0;
	}
	return 0;
}
