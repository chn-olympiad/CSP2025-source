#include<bits/stdc++.h>
using namespace std;
int n,m,r,t,x=1,y=1;
priority_queue<int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;cin>>r;q.push(r);
	for(int i=2;i<=n*m;i++){
		cin>>t;q.push(t);
	}
	for(int i=1;i<=n*m;i++){
		if(q.top()==r){
			cout<<x<<" "<<y;
			return 0;
		}
		q.pop();
		if(x%2==1 && y<n) y++;
		else if(x%2==0 && 1<y) y--;
		else x++;
	}
	return 0;
}
