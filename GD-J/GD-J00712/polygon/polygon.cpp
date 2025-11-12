#include<bits/stdc++.h>
using namespace std;

const long long MOD=998244353;
const int MAXN=5000;
long long n,ans=0;
int a[MAXN+5];
bool vis[MAXN+5];

bool polygon(){
	int sum=0;
	int m=0;
	int cnt=0;
	for(int j=1;j<=n;j++){
		if(!vis[j]) continue;
		cnt++;
		sum=sum+a[j];
		m=max(m,a[j]);
	}
	if(sum>2*m&&cnt>=3){
		ans++;
		ans%=MOD;
		//cout<<sum<<" "<<m<<endl;
		return true;
	}
	return false;
}

void dfs(int s){
	polygon();
	if(s==n){
		return;
	}
	for(int d=s+1;d<=n;d++){
		vis[d]=true;
		dfs(d);
		vis[d]=false;
	}
	return;
}

int main(){
	//AC from 1 to 3.
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		memset(vis,false,n);
		vis[i]=true;
		dfs(i);
	}
	cout<<ans;
	return 0;
}
