#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
const int M=998244353;

int a[N],vis[N];
int n;
int ans;


int cal(int x){
	int mx=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			x+=a[i];
			mx=max(mx,a[i]);
		}
	}
	if(x>mx*2)return 1;
	else return 0;
}

void dfs(int cur){
	if(cur-1==n){
		return ;
	}
	for(int i=cur;i<=n;i++){
		vis[i]=1;
		if(cal(0)==1){
			ans++;
		}
		dfs(i+1);
		vis[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		dfs(1);
		cout<<ans;
	}
	
	
	return 0;
}