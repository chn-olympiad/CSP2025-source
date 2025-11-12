#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
//long long a[N][3];
int n,t;
priority_queue<int,vector<int>,greater<int> > q[3];
struct node{
	int s,id;
}a[3];
int main(){
//	system("fc club5.ans club.out");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		while(!q[0].empty())q[0].pop();
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		for(int i=1;i<=n;i++){
			cin>>a[0].s>>a[1].s>>a[2].s;
			a[0].id=0;
			a[1].id=1;
			a[2].id=2;
			sort(a,a+3,[](node x,node y){
				return x.s>y.s;
			});
			if(q[a[0].id].size()==n/2){
				if(a[0].s-a[1].s<q[a[0].id].top()){
					ans+=a[1].s;
//					cout<<a[0].s<<endl;
					q[a[1].id].push(-1);
				}
				else {
					ans+=a[0].s;
					ans-=q[a[0].id].top();
					q[a[0].id].pop();
					q[a[0].id].push(a[0].s-a[1].s);
				}
			}
			else {
				q[a[0].id].push(a[0].s-a[1].s);
				ans+=a[0].s;
			}
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
