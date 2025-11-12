#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

int n;
int a[5001];
int ans;
bool b=0;

void dfs(int d,int s,int ma,int c,bool b){
	if(s>2*ma&&c>=3&&b){
		ans++;
		ans%=mod;
	}
	if(d==n){
		return ;
	}
	
	dfs(d+1,s+a[d+1],max(ma,a[d+1]),c+1,1);
	dfs(d+1,s,ma,c,0);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=1) b=1;
	}
	if(n<=100){
		for(int i=1;i<=n-1;i++){
			dfs(i,a[i],a[i],1,1);
		}
		ans%=mod;
		cout<<ans;
		return 0;
	}
	if(b==1){
		for(int i=1;i<=n-2;i++){
			ans*=2;
			ans%=mod;
		}
		cout<<ans;
	}
	
	return 0;
}
