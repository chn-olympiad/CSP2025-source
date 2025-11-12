#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
vector<int>raw(N);
vector<int>pre(N);
vector<pair<int,int>>lr(N);
bool ck(int i,int j){
	for(auto v:lr){
		if(i<=v.second&&i>=v.first){
			return true;
		}else if(j<=v.second&&j>=v.first){
			return true;
		}
	}
	return false;
}
int dp[N*20];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>raw[i];
		pre[i]=pre[i-1]^raw[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int a=pre[i-1];
			int b=pre[j];
//			cout<<i-1<<" "<<j<<" "<<a<<" "<<b<<" "<<(a^b)<<endl;
			if((a^b)==k){
				if(ck(i,j))continue;
				lr.push_back({i,j});
				ans++;
			}
		}	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
