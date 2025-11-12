#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int cnt,w;
}b[3];
struct node2{
	int fst,scd;
};
vector<node2>v[3];
bool cmp(node x,node y){
	return x.w>y.w;
}
bool cmp2(node2 x,node2 y){
	return x.fst-x.scd<y.fst-y.scd;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=0;i<3;i++)	v[i].clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>b[j].w;b[j].cnt=j;
			}
			sort(b,b+3,cmp);
			v[b[0].cnt].push_back({b[0].w,b[1].w});
			ans+=b[0].w;
		}
		for(int i=0;i<3;i++){
			int sz=v[i].size();
			if(sz>(n>>1)){
				sort(v[i].begin(),v[i].end(),cmp2);
				for(int j=0;j<sz-(n>>1);j++)
					ans+=v[i][j].scd-v[i][j].fst;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
