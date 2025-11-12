#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],tot;
string str;
void dfs(int x,int y,int dis,int num){
//	cout<<x<<" "<<y<<" "<<dis<<" "<<num<<"\n";
	if(num==tot){
		cout<<y<<" "<<x;
		return;
	}
	x+=dis;
	if(x>n) dfs(n,y+1,-1,num+1);
	else if(x<1) dfs(1,y+1,1,num+1);
	else dfs(x,y,dis,num+1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++) {
		cin>>a[i];
		if(a[i]>a[1]) tot++;
	}
//	cout<<tot<<"\n";
	dfs(1,1,1,0);
	return 0;
}
/*
2 2
98 99 100 97
*/