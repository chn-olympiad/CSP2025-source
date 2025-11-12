#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b[101],ans,num;
void dfs(int x,int y){
	if(b[n*x-n+y]==ans){
		cout<<x<<" "<<y;
		return;
	}else{
		if(x%2==1){
			if(y!=n){
				dfs(x,y+1);
			}else{
				dfs(x+1,y);
			}
		}else{
			if(y==1){
				dfs(x+1,y);
			}else{
				dfs(x,y-1);
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	num=n*m;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		b[num]=a[i];
		num--;
	}
	dfs(1,1);
	return 0;
}
