#include<bits/stdc++.h>
using namespace std;
int in(){
	int a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())a=(a<<1)+(a<<3)+c-'0';
	return a*f;
}
const int N=510,mod=998244353;
int n,m;
vector<int> epl;
long long pts[N];
int c[15];
int dfs(int now,int d){
	if(now==n)
	{
		if(d>=m)return 1;
		else return 0;
	}else{
		int ans=0;
		for(int i=0;i<=n;i++){
			if(pts[i]){
				pts[i]--;
				if(i>now-d&&c[now+1])ans=(ans+dfs(now+1,d+1))%mod;
				else {
					ans=(ans+dfs(now+1,d))%mod;
				}
				pts[i]++;
			}
		}
		return ans;
	}
}
void bs(){
	int ans=0;
	for(auto i:epl)c[i]=1;
	for(int i=0;i<=n;i++){
		if(pts[i]){
			pts[i]--;
			if(i!=0&&c[1])ans=(ans+dfs(1,1)*(pts[i]+1))%mod;
			else{
				ans=(ans+dfs(1,0)*(pts[i]+1))%mod;
			}
			pts[i]++;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in();
	m=in();
	char ch;
	for(int i=1;i<=n;i++){
		ch=getchar();
		while(!isdigit(ch))ch=getchar();
		if(ch=='1')epl.push_back(i);
	}
	for(int i=1;i<=n;i++){
		pts[in()]++;
	}
	if(n<=10){
		bs();
		return 0;
	}
	for(int i=n;i>=0;i--)pts[i]+=pts[i+1];
	int ans=0;if(m==n){
		if(epl.size()!=n&&pts[0]!=0)cout<<0<<"\n";
		else{
			for(int i=1;i<=n;i++)
				ans=(ans*(n-i+1))%mod;
			cout<<ans<<'\n';
		}
	}else if(epl.size()==n){
		
	}
	return 0;
	
}
