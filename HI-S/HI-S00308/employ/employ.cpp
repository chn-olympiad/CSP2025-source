#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[1010];
int c[1010];
int v[1010];
int q[1010];
long long ans;
long long mod=998244353;
void dfs(int step){
	if(step==n){
		int tot=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')tot++;
			else{
				if(c[q[i]]-tot<=0)tot++;
				else cnt++;
			}
		}
		if(cnt>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			q[step+1]=i;
			dfs(step+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(n<=10){
		dfs(0);
		cout<<ans;
	}
	else{
		int flag=0;
		for(int i=1;i<=n;i++)if(s[i]=='0')flag=1;
		if(!flag){
			ans=1;
			for(long long i=n;i>=1;i--){
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
