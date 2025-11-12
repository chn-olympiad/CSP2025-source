#include<bits/stdc++.h>
using namespace std;

int n;
const int N=5100;
const int mod=998244353;
int a[N];

void inc(int &x,int y){
	x=(x+y)%mod;
}

bool vis[N];
int ans;

void print(){
	for(int i=1;i<=n;i++){
		if(vis[i]) cout<<i<<' ';
	}
	cout<<endl;
}

void dfs(int now,int cnt,int sum,int _max){
//	print();
	if(cnt>=3&&sum>_max*2){
		inc(ans,1);
//		print();
	}
	if(now==n) return;
	for(int i=now+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,cnt+1,sum+a[i],max(_max,a[i]));
			vis[i]=0;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<':'<<endl;
		if(!vis[i]){
			vis[i]=1;
			dfs(i,1,a[i],a[i]);
			vis[i]=0;
		}
	}
	cout<<ans;
	
	return 0;
}
