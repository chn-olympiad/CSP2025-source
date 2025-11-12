#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int score_of_r;
	cin>>score_of_r;
	pq.push(score_of_r);
	for(int i=2; i<=n*m; i++) {
		int a;
		cin>>a;
		pq.push(a);
	}
	int cnt=0;
	while(!pq.empty()) {
		cnt++;
		if(pq.top()==score_of_r) {
			int ans1=0,ans2=0;
			ans1=(cnt-1)/n+1;
			if(ans1%2==1) {
				ans2=cnt-n*(ans1-1);
			} else {
				ans2=cnt-n*(ans1-1);
				ans2=n-ans2+1;
			}
			cout<<ans1<<' '<<ans2;
			break;
		}
		pq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

