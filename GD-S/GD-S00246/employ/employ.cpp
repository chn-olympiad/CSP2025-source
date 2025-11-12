#include<iostream>
using namespace std;
const int si=5e2+10;
int n,m,a[si],ans=0;
bool s[si],v[si];
int c[si];
int in(){
	int kkk=0;
	scanf("%lld",&kkk);
	return kkk;
}
bool check(){
	int ba=0;
	for(int i=1;i<=n;i++)
		if(s[i]==0||ba>=c[i])++ba;
	return n-ba>=m;
}
void dfs(int u){
	if(u==n+1){
		if(check())++ans;
		return;
	}for(int i=1;i<=n;i++)
		if(!v[i]){
			v[i]=1,a[u]=i;
			dfs(u+1);
			v[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in(),m=in();
	for(int i=1;i<=n;i++)
		scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++)
		c[i]=in();
	dfs(1);
	printf("%d",ans);
	return 0;
}
