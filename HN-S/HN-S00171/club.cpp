#include<bits/stdc++.h>
using namespace std;
int n,T,a[100005][3],ans,b[100005];
vector<int>v[3];
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cin>>T;
	while(T--){
		cin>>n,ans=0;
		for(int i:{0,1,2})
			v[i].clear();
		for(int i=1;i<=n;i++)
			for(int j:{0,1,2})
				cin>>a[i][j];
		for(int i=1,x;i<=n;i++){
			x=max_element(a[i],a[i]+3)-a[i],v[x].emplace_back(i),ans+=a[i][x],b[i]=0;
			for(int y:{0,1,2})
				if(x!=y)
					b[i]=max(b[i],a[i][y]);
		}
		for(int o:{0,1,2})
			if((int)v[o].size()>n>>1){
				vector<int>vec;
				for(int x:v[o])
					vec.emplace_back(a[x][o]-b[x]);
				sort(vec.begin(),vec.end());
				for(int i=0;i<(int)v[o].size()-(n>>1);i++)
					ans-=vec[i];
				break;
			}
		cout<<ans<<'\n';
	}
	return 0;
}