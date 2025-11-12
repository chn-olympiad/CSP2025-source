#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=1,a[500001],dp[1001][1001],res=0;
int d1[1001],d2[1001];
vector<pair<int,int>>v;
bool flag=1;
void dfs(int p,int s){
	if(p>cnt){
		res=max(res,s);
		return;
	}
	dfs(p+1,s);
	for(auto e:v){
		if(e.first>=d1[p])return;
		if(e.second>=d1[p])return;
		if(e.second>=d2[p])return;
	}
	v.push_back({d1[p],d2[p]});
	dfs(p+1,s+1);
	v.pop_back();
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=0;
	}
	memset(dp,0x3f,sizeof(dp));
	if(n<=20){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j)dp[i][j]=a[i];
				else dp[i][j]=dp[i][j-1]^a[j];
				if(dp[i][j]==k)d1[cnt]=i,d2[cnt++]=j;
			}
		}
		dfs(1,0);
		cout<<res<<'\n';
	}else if(k==0){
		for(int i=2;i<=n;){
			if(a[i-1]==a[i]){
				res++;
				i+=2;
			}else i++;
		}
		cout<<res<<'\n';
	}else if(flag){
		if(k>1)cout<<0<<'\n';
		else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)res++;
			}
			cout<<res<<'\n';
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				bool f=1;
				if(i==j)dp[i][j]=a[i];
				else dp[i][j]=dp[i][j-1]^a[j];
				if(dp[i][j]==k){
//					cout<<i<<' '<<j<<'\n';
					for(auto e:v){
						if(e.first>=i||e.second>=i||e.second>=j){
							f=0;
							break;
						}
					}
					if(f)res++,v.push_back({i,j});
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
