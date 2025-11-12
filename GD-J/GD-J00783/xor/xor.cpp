#include<bits/stdc++.h>
using namespace std;

int n,x,ans;
int a[500010];
vector<int > num[500010];

void dfs(int i,int j,int t){
	if(t>ans){
		ans=t;
	}
	if(i>n||j>i-1){
		return ;
	}
	
	
	if(num[i][j]==x){
		t++;
		dfs(i+1,j+1,t);
		t--;
	}
	dfs(i+1,j,t);
	dfs(i,j+1,t);
	return;
}

int main(){
	
	
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i-2;j++){
			num[i].push_back(0);
		}
		num[i].push_back(a[i]);
	}
	
	
	for(int i=2;i<=n;i++){
		int tmp=a[i];
		for(int j=0;j<=i-2;j++){
			num[i][j]=int( num[i-1][j]^tmp );
		}
	}
	
	dfs(1,0,0);
	cout<<ans;
	
	return 0;
} 
