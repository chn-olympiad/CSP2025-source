#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
priority_queue<int> q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int s=0;s<3;s++)
			while(q[s].size()) q[s].pop();
		for(int i=1;i<=n;i++){
			int x,y,z; cin>>x>>y>>z;
			ans+=max(x,max(y,z));
			if(x>=y&&x>=z) q[0].push(-x+max(y,z));
			else if(y>=z)  q[1].push(-y+max(x,z));
			else 		   q[2].push(-z+max(x,y));
		}
		for(int s=0;s<3;s++)
			while(q[s].size()>n/2)
				ans+=q[s].top(),q[s].pop();
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
6
6 6 6
6 6 6
6 6 6
6 6 6
6 6 6
6 6 6

1
6
1 2 3
3 2 1
1 2 3
3 2 1
1 2 3
3 2 1

1
2
1 0 0
2 1 1
*/
