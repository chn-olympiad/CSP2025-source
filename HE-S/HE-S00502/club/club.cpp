#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e6;

int n,t;
int a[MAX][5],x[5];
int dfs(int k){
	if(k>n)return 0;
	if(x[1]>n/2 || x[2]>n/2 || x[3]>n/2 )return 0;
	int sum=0;
	for(int i=1;i<=3;i++){
		if(x[i]+1>n/2)continue;
		x[i]++;
		sum=max(sum,dfs(k+1)+a[k][i]);
		x[i]--;
	}
	return sum;
}
void chu(){
	for(int i=1;i<=n;i++){
		a[i][1]=0;
		a[i][2]=0;
		a[i][3]=0;
	}
	x[1]=0;
	x[2]=0;
	x[3]=0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<dfs(1)<<"\n";
		chu();
	}
	
	
	
	
	return 0;
}

