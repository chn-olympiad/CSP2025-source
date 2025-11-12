#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m;
char s[505];
int c[505];
const int mod=998244353;
int sum[505],ans;
bool f[505];
void pd(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')cnt++;
		else{
			if(cnt>=c[sum[i]])cnt++;
		}
	}
	if(n-cnt>=m)ans++;
}
void dfs(int k){
	if(k>n){
		pd();
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=true;
			sum[k]=i;
			dfs(k+1);
			f[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]); 
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
/*
3 2
101
1 1 2

*/
