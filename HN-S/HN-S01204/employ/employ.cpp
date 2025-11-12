#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define int long long
int n,m;
int tmp[505],ans=0,c[505];
string str;
bool vis[505]={0};
const int mod=998244353;
void count(){
	int now=0,temp_ans=0;
	for(int i=1;i<=n;i++){
		if(c[tmp[i]]>now&&str[i-1]=='1')++temp_ans;
		else ++now; 
	}
	if(temp_ans>=m)ans=(ans+1)%mod;
}
void dfs(int k){
	if(k>n){
		count();
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=1;
		tmp[k]=i;
		dfs(k+1);
		vis[i]=0;
		tmp[k]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	bool is1=1;
	for(int i=0;i<n;++i)is1&=(str[i]=='1');
	for(int i=1;i<=n;++i)cin>>c[i]; 
	cout<<is1;
	if(is1){
		int total=1;
		int tmp_cnt_1=0;
		for(int i=1;i<=n;++i)if(c[i])++tmp_cnt_1;
		int tmp_cnt_0=n-tmp_cnt_1;
		for(int k=1;k<=1000;++k){
			for(int i=1;i<=n;++i){if(c[i]<=tmp_cnt_0){tmp_cnt_0++,tmp_cnt_1--;}}
		}
		for(int i=2;i<=tmp_cnt_1;++i)total=(total*i)%mod;
		cout<<total;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
