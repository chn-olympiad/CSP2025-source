#include<bits/stdc++.h>
using namespace std;
int n,m,sc;
priority_queue<int> q;
void dfs(int x,int y){
	if(q.top()==sc){
		cout<<x<<" "<<y;
		exit(0);
	}
	q.pop();
	if((x%2==0&&y==1)||(x%2==1&&y==m)){
		if(x==n)return;
		dfs(x+1,y);
	}
	else if(x%2)dfs(x,y+1);
	else dfs(x,y-1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i==1)sc=x;
		q.push(x);
	}
	dfs(1,1);
}
