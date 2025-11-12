//100+40+0+20=160
#include<iostream>
#include<stdio.h>
using namespace std;
bool use[100000];
char s[100000];
int n,m,c[100000],ans;
int q[100000],cnt;
void check(){
	int fai=0,suc=0;
	for(int i=1;i<=n;i++){
		if(fai>=c[q[i]]){
			fai++;
			continue;
		}
		if(s[i]=='0')fai++;
		else suc++;
	}
	if(suc>=m)ans++;
}
void dfs(int x){
	if(x==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(use[i])continue;
		q[++cnt]=i;
		use[i]=true;
		dfs(x+1);
		use[i]=false;
		--cnt;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	if(cnt>m){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
