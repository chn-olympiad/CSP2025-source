#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans,f[505];
char s[505];
void dfs(int i,int l,int d,int x){
	if(d==n){
		if(x>=m)ans++;
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				f[i]=1;
				if(l>=c[i]||s[d]=='0'){
					dfs(i,l+1,d+1,x);
				}else{
					dfs(i,l,d+1,x+1);
				}
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(0,0,0,0);
	if(n>20){
		printf("0");
		return 0;
	}
	printf("%d",ans);
	return 0;
}