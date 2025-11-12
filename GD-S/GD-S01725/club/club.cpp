#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+1;
struct poi{
	int w,i;
}a[4];
bool cmp(poi s1,poi s2){
	return s1.w>s2.w;
}
long long t,n,ans;
priority_queue<long long> q[4];
void clear(){
	while(!q[1].empty())q[1].pop();
	while(!q[2].empty())q[2].pop();
	while(!q[3].empty())q[3].pop();
}
void solve(){
	cin>>n;
	ans=0;
	for(long long i=1;i<=n;i++){
		cin>>a[1].w>>a[2].w>>a[3].w;
		a[1].i=1,a[2].i=2,a[3].i=3;
		sort(a+1,a+4,cmp);
		q[a[1].i].push(a[2].w-a[1].w);
		ans+=a[1].w; 
		if((long long)q[a[1].i].size()>n/2){
			long long w=-q[a[1].i].top();
			q[a[1].i].pop();
			ans-=w;
		}
		
	}
	cout<<ans<<"\n";
	clear();
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
