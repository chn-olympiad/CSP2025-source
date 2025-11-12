#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b,c;
}a[100010];
int vis[100010],ans;
void dfs(int k,int n,int w,int a1,int b1,int c1,int an){
	if(k==n){
		ans=max(ans,an);
		return ;
	}
	if(k>n) return ;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a1<w){
				an+=a[i].a;
				dfs(k+1,n,w,a1+1,b1,c1,an);
				an-=a[i].a;
			}
			if(b1<w) dfs(k+1,n,w,a1,b1+1,c1,an+a[i].b);
			if(c1<w) dfs(k+1,n,w,a1,b1,c1+1,an+a[i].c);
			vis[i]=0;
		}
	}
}
bool cmp(node a,node b){
	return a.a>b.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		int n,T=0,answ=0;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b==a[i].c&&a[i].c==0) T++;
		}
		if(T==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)answ+=a[i].a;
			cout <<answ<<endl;
		}
		else{
			dfs(0,n,n/2,0,0,0,0);
			cout <<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
