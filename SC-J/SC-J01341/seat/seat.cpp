#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,cnt,r;
priority_queue<int>q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a;
	q.push(a);
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	while(q.top()!=a){
		q.pop();
		cnt++;
	}
	++cnt;
	if(cnt<=n){
		cout<<1<<" "<<cnt;
		return 0;
	}
	r=cnt/n;
	if(cnt%n==0){
		if(r%2==1){
			cout<<r<<" "<<n;
		}
		else{
			cout<<r<<" "<<1;
		}
		return 0;
	}
	if(r%2==1){
		cout<<r+1<<" "<<n-(cnt%n)+1;
	}
	else{
		cout<<r+1<<" "<<cnt%n;
	}
	return 0;
} 