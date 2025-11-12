#include<bits/stdc++.h>
using namespace std;
int n,m,b[505],ans=0;
bool a[505],c[505];
void dfs(int now,int get){
	now++;
	if(now>n){
		if(get>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!c[i]){
			c[i]=true;
			if(!a[now]||b[i]<=now-get-1)dfs(now,get);
			else dfs(now,get+1);
			c[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	bool has1=true,has0=true;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			a[i]=false;
			has0=false;
		}
		else{
			a[i]=true;
			has1=false;
		}
	}
	if(has1&&m==0){
		printf("0\n");
		return 0;
	}
	if(has0){
		long long sum=n;
		for(long long i=2;i<n;i++){
			sum*=i;
			sum%=998244353;
		}
		printf("%lld\n",sum);
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}
