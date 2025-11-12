#include<bits/stdc++.h>
using namespace std;

int vis[6000];
int t;
int n;
int a[6000][4];
int num=0;

void dfs(int x,int sum){
	if(x==n+1){
		num=max(sum,num);
		return;
	}
	
	for(int i=1;i<=3;i++){
		if(vis[i]<n/2){
			vis[i]++;
				//cout<<i<<x<<"  ";
			dfs(x+1,sum+a[x][i]);
			vis[i]--;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		num=0;
		for(int i=1;i<=3;i++)vis[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<num<<endl;
	}
	
	
	return 0;
}
