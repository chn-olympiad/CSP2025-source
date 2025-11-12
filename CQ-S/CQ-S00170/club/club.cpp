#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
struct node{
	int x,d;
};
bool cmp(node a,node b){
	return a.d<b.d;
}
vector<node> v[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		v[1].clear();
		v[2].clear();
		v[3].clear();
		cin>>n;
		int x,y,z,ans=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				ans+=x;
				v[1].push_back({i,min(x-y,x-z)});
			}
			else if(y>=x&&y>=z){
				ans+=y;
				v[2].push_back({i,min(y-x,y-z)});
			}
			else{
				ans+=z;
				v[3].push_back({i,min(z-x,z-y)});
			}
		}
		if(v[1].size()>n/2){
			sort(v[1].begin(),v[1].end(),cmp);
			int cnt=v[1].size()-n/2;
			for(int i=0;i<cnt;i++) ans-=v[1][i].d;
		}
		else if(v[2].size()>n/2){
			sort(v[2].begin(),v[2].end(),cmp);
			int cnt=v[2].size()-n/2;
			for(int i=0;i<cnt;i++) ans-=v[2][i].d;
		}
		else if(v[3].size()>n/2){
			sort(v[3].begin(),v[3].end(),cmp);
			int cnt=v[3].size()-n/2;
			for(int i=0;i<cnt;i++) ans-=v[3][i].d;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//4.4MB
//1s 512MB
