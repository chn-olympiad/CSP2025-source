#include<iostream>
#include<algorithm>
using namespace std;
long long a=0,b=0,f[1005],d=0;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(long long dang,long long x,long long y){
	if(f[dang]==d){
		cout<<x<<' '<<y; 
	}
	else if((x%2==0&&y==1)||(x%2==1&&y==b)) dfs(dang+1,x+1,y);
	else if(x%2==0){
		dfs(dang+1,x,y-1);
	}
	else{
		dfs(dang+1,x,y+1);
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>f[i];
	}
	d=f[1];
	sort(1+f,1+f+a*b,cmp);
	dfs(1,1,1);
	return 0;
}
