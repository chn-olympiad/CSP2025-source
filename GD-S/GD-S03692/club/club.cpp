#include <bits/stdc++.h>
#define int long long
using namespace std; 
const int kMaxN = 1e5+3;

int n,t;
int members[kMaxN][3];
int club_total_members[4];

int DFS(int s){
	if (s>n) {
		return 0;
	}
	
	int res{0};
	for (int i=0;i<3;i++) {
		if (2*club_total_members[i]+2<=n) {
			res=max(res,DFS(s+1)+members[s][i]);
		}
	}
	return res;
}

signed main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for (int terms=1;terms<=t;terms++) {
		cin>>n;
		fill(&members[0][0],&members[n][2]+1,-1);
		fill(club_total_members,club_total_members+4,0);
		for (int i=1;i<=n;i++) {
			cin>>members[i][0]>>members[i][1]>>members[i][2];
		}	
		cout<<DFS(1)<<endl;
	}
	return 0;
}

