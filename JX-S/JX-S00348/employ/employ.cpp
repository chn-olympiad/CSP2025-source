#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int a[505];
int ans=0;
int st[505];

void dfs(int k,int sum){// sum -> last value he
	if(k>n){
		ans++;
		//puts("");
		return ;
	}for(int i=1;i<=n;i++){
		if(!st[i]){
			//cout<<k<<'_'<<i<<'-'<<sum<<' ';
			if(a[i]>sum){
				st[i]=1;
				if(s[k-1]=='0') dfs(k+1,sum+1);
				else dfs(k+1,sum);
				st[i]=0; 
			}
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f=0;
	for(int i=0;i<n;i++) if(s[i]=='0') f=1;
	if(!f){
		long long sum=1;
		for(int i=1;i<=n;i++) sum=sum*i%mod;
		cout<<sum<<'\n';
	}else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
