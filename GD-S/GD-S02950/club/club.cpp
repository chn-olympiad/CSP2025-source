#include<bits/stdc++.h>
using namespace std;

int t, n;
int l[100005][3];
long long ans=-1;
int m=-1;

void bfs() {
	vector<vector<long long>> q;
	q.push_back({0, 0, 0, 0, 0});
	while (!q.empty()) {
		vector<vector<long long>> temp = q;
		q={};
		long long c1=0, c2=0, c3=0;
		
		for (auto i:temp) {
			if (i[0]>=n) {
				ans = max(ans, i[1]);
				continue;
			}
			if (i[2]==n/2) {
				if (i[1]<c1) continue;
				c1 = i[1];
			} else if (i[3]==n/2) {
				if (i[1]<c2) continue;
				c2 = i[1];
			} else if (i[4]==n/2) {
				if (i[1]<c3) continue;
				c3 = i[1];
			}
			
			if (i[2]<n/2) {
				q.push_back({i[0]+1, i[1]+l[i[0]][0], i[2]+1, i[3], i[4]});
			}
			if (i[3]<n/2 && m!= 1) {
				q.push_back({i[0]+1, i[1]+l[i[0]][1], i[2], i[3]+1, i[4]});
			} 
			if (i[4]<n/2 && m!= 1 && m!= 2) {
				q.push_back({i[0]+1, i[1]+l[i[0]][2], i[2], i[3], i[4]+1});
			}
		}
		
	}
}

int main() {
	freopen("club3.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	cin>>t;
	
	while(t--) {
		m=-1;
		cin>>n;
		int c2=0, c3=0;
		for (int i=0;i<n;i++) {
			cin>>l[i][0]>>l[i][1]>>l[i][2];
			c2+=l[i][1];
			c3+=l[i][2];
		}
		if (c2+c3==0) {
			m=1;
		} else if (c3==0){
			m=2;
		}
		ans=-1;
		bfs();
		
		cout<<ans<<endl;
	}	
	return 0;
}
