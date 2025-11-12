#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int target;
int score[1004];
int st[104][104];
void dfs(int x,int y,int num,int toward){
	if(y>m){
		cout<<"&"<<x<<"&"<<y<<endl;
		return;
	}
	
	st[x][y]=score[num];
	if(st[x][y]==target){
		cout<<y<<' '<<x<<endl;
		return;
	}
	num++;
	if(toward==1){
		if(x==n){
			dfs(x,y+1,num,2);
		}
		else{
			x++;
			dfs(x,y,num,toward);
		}
		
	}
	else if(toward==2){
		if(x==1){
			dfs(x,y+1,num,1);
		}else{
			x--;
			dfs(x,y,num,toward);
		}
		
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	target=score[1];
	sort(score+1,score+1+n*m,greater<int>() );
	dfs(1,1,1,1);
	return 0;
}
