#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105];
int top=0;
void dfs(int x){
	if(x>m){
		return ;
	}
	for(int i=(x-1)*n+1;i<=(x-1)*n+n;i++){
		if(b[i]==top){
			cout<<x<<" "<<i-(x-1)*n;
			return ;
		}
	}
	x++;
	dfs(x);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			top=a[i];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m,j=1;i>=1;j++,i--){
		b[j]=a[i];
	}
	dfs(1);
	return 0;
}
