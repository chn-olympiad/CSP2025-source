#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int mod=998244353;
int n,m,c[555],sum=0,ans=0;
string s;
vector<int> v;
int len;

void dfs(int x,int cnt,int times){
	if(x==m){
		ans+=cnt;
		ans=ans%mod;
		return ;
	}
	for(int i=times;i<v.size();i++){
		dfs(x+1,cnt*=c[v[i]],times+1);
	}
	return ;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') len++;
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(c[x]==0){
			sum++;
			v.push_back(x);
		}
		c[x]++;
	}
	if(sum<m || len<m){
		printf("0");
		return 0;
	}
	dfs(0,1,0);
	printf("%d",ans/2);

	return 0;
}

