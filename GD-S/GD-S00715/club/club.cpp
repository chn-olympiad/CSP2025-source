#include<bits/stdc++.h>
using namespace std;
int T,n,a[4],ans;
vector<int> na[4];
int red[100005];
int p[100005];
bool cmp(int ax,int by){
	if(red[ax]<red[by]) return true;
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(scanf("%d",&T);T;T--,ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int ia=0,ib=1,ic=2;
			scanf("%d%d%d",&a[0],&a[1],&a[2]);
			if(a[ia]<a[ib]) swap(ia,ib);
			if(a[ib]<a[ic]) swap(ib,ic);
			if(a[ia]<a[ib]) swap(ia,ib);
			na[ia].push_back(i);
			ans+=a[ia];
			red[i]=a[ia]-a[ib];
		}
		if(na[0].size()<na[1].size()) swap(na[0],na[1]);
		if(na[1].size()<na[2].size()) swap(na[1],na[2]);
		if(na[0].size()<na[1].size()) swap(na[0],na[1]);
		if(na[0].size()>(n>>1)){
			for(unsigned int i=0;i<na[0].size();i++) p[i+1]=na[0][i];
			sort(p+1,p+na[0].size()+1,cmp);
			for(int i=na[0].size()-(n>>1);i>=1;i--) ans-=red[p[i]];
		}
		printf("%d\n",ans);
		for(unsigned int i=1;i<=na[0].size();i++) p[i]=0;
		while(!na[0].empty()) na[0].pop_back();
		while(!na[1].empty()) na[1].pop_back();
		while(!na[2].empty()) na[2].pop_back();
	}
	return 0;
}
