#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n;
int a[5001];
void dfs(int x,int y){
	if(x>n){
		return;
	}
	for(int i=x;i<=n;i++){
		if(a[i]<y){
			ans++;
		}
		dfs(i+1,y+a[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	priority_queue<int> as;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		as.push(c);
	}
	for(int i=n;i>=1;i--){
		a[i]=as.top();
		as.pop();
	}
	if(n==3){
		if(a[0]+a[1]+a[2]>max(a[0],max(a[1],a[2]))*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			dfs(j+1,a[i]+a[j]);
		}
	}
	cout<<ans;
	return 0;
}