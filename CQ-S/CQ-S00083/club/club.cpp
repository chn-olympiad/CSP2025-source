#include<bits/stdc++.h>
using namespace std;
const int MaxN=100000;
int n;
priority_queue<int>q[3];
void Solve(){
	cin>>n;
	for(int j=0;j<3;j++)q[j]=priority_queue<int>();
	int sum=0;
	for(int i=1;i<=n;i++){
		pair<int,int>p[3];
		for(int j=0;j<3;j++)cin>>p[j].first,p[j].second=j;
		sort(p,p+3,greater<>());
		if(q[p[0].second].size()>=n/2){
			if(p[0].first+q[p[0].second].top()<max(p[1].first,p[2].first)){
				sum+=max(p[1].first,p[2].first);
			}else{
				sum+=p[0].first+q[p[0].second].top();
				q[p[0].second].pop();
				q[p[0].second].push(max(p[1].first,p[2].first)-p[0].first);
			}
		}else{
			sum+=p[0].first;
			q[p[0].second].push(max(p[1].first,p[2].first)-p[0].first);
		}
	}
	cout<<sum<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
		Solve();
	return 0;
}

