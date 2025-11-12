#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pr pair<int,int>
#define fi first
#define se second
priority_queue<int, vector<int>, greater<int> > cnt[3];
int a[100005][3];
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int T;
	cin>>T;
	while(T--){
		while(!cnt[0].empty()) cnt[0].pop();
		while(!cnt[1].empty()) cnt[1].pop();
		while(!cnt[2].empty()) cnt[2].pop();
		int n;
		cin>>n;
		int s=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>a[i][1] && a[i][0]>a[i][2]) cnt[0].push(a[i][0]-max(a[i][1], a[i][2]));
			else if(a[i][1]>a[i][0] && a[i][1]>a[i][2]) cnt[1].push(a[i][1]-max(a[i][0], a[i][2]));
			else cnt[2].push(a[i][2]-max(a[i][1], a[i][0]));
			s+=max(a[i][0], max(a[i][1], a[i][2]));
		}
		if(cnt[0].size()>n/2){
			while(cnt[0].size()>n/2) s-=cnt[0].top(), cnt[0].pop();
		}
		if(cnt[1].size()>n/2){
			while(cnt[1].size()>n/2) s-=cnt[1].top(), cnt[1].pop();
		}
		if(cnt[2].size()>n/2){
			while(cnt[2].size()>n/2) s-=cnt[2].top(), cnt[2].pop();
		}
		cout<<s<<'\n';
	}
	return 0;
}

