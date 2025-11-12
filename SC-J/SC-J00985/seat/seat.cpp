#include<bits/stdc++.h>
#include <queue>
using namespace std;
int n,m,x,j,b[105],cnt,dx,dy;
priority_queue <int> a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>b[++x];
			a.push(b[x]);
		}
	}
	while(!a.empty()){
		cnt++;
		if(b[1]==a.top()){
			break;
		}
		a.pop();
	}
	dx=ceil(cnt*1.0/n);
	if(dx%2==0){
		dy=(m-cnt%n+1);
	}else{
		if(cnt%n==0){
			dy=n;
		}else{
			dy=cnt%n;
		}
		
	}
	cout<<dx<<" "<<dy;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 