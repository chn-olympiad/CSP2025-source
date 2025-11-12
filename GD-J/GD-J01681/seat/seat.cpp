#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
int r;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int y,int add,int idx){//x==hang y==lie
	if(a[idx]==r){
		cout<<y<<' '<<x;
		return;
	}
	x+=add;
	int dadd=add;
	if(x>n){
		x-=add;
		y+=1;
		dadd=-1;
	}
	else if(x<1){
		x-=add;
		y+=1;
		dadd=1;
	}
	dfs(x,y,dadd,idx+1);
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int k;
			cin>>k;
			a.push_back(k);
		}
	} 
	r=a.front();
	sort(a.begin(),a.end(),cmp);
	int i=1,j=1;
	dfs(i,j,1,0);
	return 0;
}
