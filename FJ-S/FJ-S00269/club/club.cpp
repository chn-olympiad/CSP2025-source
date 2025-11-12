#include<bits/stdc++.h>
using namespace std;
vector<int>vec[3];
int a[100005][3];
int ma[100005];
int mma[100005];
bool o(int x,int y){
	return mma[x]<mma[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		vec[0].clear();
		vec[1].clear();
		vec[2].clear();
		int n;
		scanf("%d",&n);
		int s=0;
		for(int i=0;i<n;i++){
			ma[i]=0;
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
				ma[i]=max(ma[i],a[i][j]);
			}
			if(ma[i]==a[i][0]){
				vec[0].emplace_back(i);
				mma[i]=ma[i]-max(a[i][1],a[i][2]);
			}
			else if(ma[i]==a[i][1]){
				vec[1].emplace_back(i);
				mma[i]=ma[i]-max(a[i][0],a[i][2]);
			}
			else{
				vec[2].emplace_back(i);
				mma[i]=ma[i]-max(a[i][0],a[i][1]);
			}
			s+=ma[i];
		}
		int maa=max({vec[0].size(),vec[1].size(),vec[2].size()});
		if(maa>(n>>1)){
			int p;
			for(int i=0;i<3;i++){
				if(vec[i].size()==maa){
					p=i;
					break;
				}
			}
			sort(vec[p].begin(),vec[p].end(),o);
			int m=maa-(n>>1);
			for(int i=0;i<m;i++){
				s-=mma[vec[p][i]];
			}
		}
		printf("%d\n",s);
	}
}
