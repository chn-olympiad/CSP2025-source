#include<bits/stdc++.h>
using namespace std;
void file_init(){
#ifndef LOCAL
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#else
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	return;
}
void fast_read(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return;
}
int n;
const int N=1e5+10;
int a[N][3];
void read(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	return;
}
int ans;
priority_queue<int,vector<int>,greater<int>>q[3];
void init(){
	for(int i=1;i<=n;i++){
		int mx1=(a[i][0]>a[i][1]?0:1),mx2=(a[i][0]<a[i][1]?0:1);
		if(a[i][mx1]<=a[i][2]){
			mx2=mx1;
			mx1=2;
		}else if(a[i][mx2]<a[i][2]){
			mx2=2;
		}
		ans+=a[i][mx1];
		q[mx1].push(a[i][mx1]-a[i][mx2]);
//		cerr<<mx1<<' '<<mx2<<'\n';
	}
//	cerr<<'\n';
	return;
}
void solve(){
	for(int i=0;i<3;i++){
		while(q[i].size()>(n>>1)){
			ans-=q[i].top();
			q[i].pop();
		}
	}
	return;
}
void clear(){
	ans=0;
	for(int i=0;i<3;i++){
		while(!q[i].empty()){
			q[i].pop();
		}
	}
	return;
}
int main(){
	file_init();
	fast_read();
	int T;
	cin>>T;
	while(T--){
		clear();
		read();
		init();
		solve();
		cout<<ans<<'\n';
	}
	return 0;
}
