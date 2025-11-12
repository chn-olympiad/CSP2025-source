#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+10;
int n;
struct node{
	int x,y,z;
}a[maxn];
int check(int x,int y,int z){
	if(x>=y&&x>=z)return 1;
	else if(y>=x&&y>=z)return 2;
	else return 3;
}
vector<int>vec[4];
int cmp(int x,int y){
	return min(a[x].x-a[x].y,a[x].x-a[x].z)>min(a[y].x-a[y].y,a[y].x-a[y].z);
}
int cmp2(int x,int y){
	return min(a[x].y-a[x].x,a[x].y-a[x].z)>min(a[y].y-a[y].x,a[y].y-a[y].z);
}
int cmp3(int x,int y){
	return min(a[x].z-a[x].x,a[x].z-a[x].y)>min(a[y].z-a[y].x,a[y].z-a[y].y);
}

void mian(){
	cin>>n;
	vec[1].clear();vec[2].clear();vec[3].clear();
	for(int i = 1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		vec[check(a[i].x,a[i].y,a[i].z)].push_back(i);
	}
	int ans = 0;
	for(auto to:vec[1])ans+=a[to].x;
	for(auto to:vec[2])ans+=a[to].y;
	for(auto to:vec[3])ans+=a[to].z;
	
	
	
	
	sort(vec[1].begin(),vec[1].end(),cmp);
	
	while(vec[1].size()>n/2){
		int x = vec[1].back();vec[1].pop_back();
		ans-=min(a[x].x-a[x].y,a[x].x-a[x].z);
	}
	sort(vec[2].begin(),vec[2].end(),cmp2);
	while(vec[2].size()>n/2){
		int x = vec[2].back();vec[2].pop_back();
		ans-=min(a[x].y-a[x].x,a[x].y-a[x].z);
	}
	sort(vec[3].begin(),vec[3].end(),cmp3);
	while(vec[3].size()>n/2){
		int x = vec[3].back();vec[3].pop_back();
		ans-=min(a[x].z-a[x].x,a[x].z-a[x].y);
	}
	
	cout<<ans<<'\n';
	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		mian();
	}
} 

