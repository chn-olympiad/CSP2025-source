#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],s,ans1[110],ans2[110];
bool cmp(int x,int y){
	return x>y;
}
int solve(int x,int y,int cnt,int jo){
	if(x>n||x<1||y>m||y<1||cnt>n*m){
		return 0;
	}
	ans1[a[cnt]]=x,ans2[a[cnt]]=y;
	if(jo%2==0){
		if(y==1){
			solve(x+1,y,cnt+1,jo+1);
		}
		else{
			solve(x,y-1,cnt+1,jo);
		}
	}
	else if(jo%2!=0){
		if(y==m){
			solve(x+1,y,cnt+1,jo+1);
		}
		else{
			solve(x,y+1,cnt+1,jo);
		}
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	solve(1,1,1,1);
	cout<<ans1[s]<<" "<<ans2[s];
	return 0;
}
