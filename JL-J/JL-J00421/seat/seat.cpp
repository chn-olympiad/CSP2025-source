#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],r1,r2,s[100][100];
void dfs(int x,int y,int step,int t){
	if(step==r2){
		cout<<x<<" "<<y<<endl;
		return ;
	}
	if(t==1){
		if(y==n){
			dfs(x+1,y,step+1,2);
		}else{
			dfs(x,y+1,step+1,1);
		}
	}else{
		if(y==1){
			dfs(x+1,y,step+1,1);
		}else{
			dfs(x,y-1,step+1,2);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r1=a[i];
	}
	sort(a+1,a+m*n+1);
	reverse(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r1){
			r2=i;
		}
	}
	dfs(1,1,1,1);
	return 0;
}
