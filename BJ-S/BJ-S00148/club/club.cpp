#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
struct node{
	int a,b,c;
};
node e[N];
bool cmp1(node x1,node x2){
	return x1.a>x2.a;
}
bool cmp2(node x1,node x2){
	return x1.b>x2.b;
}
void dfs(int u,int x,int y,int z,int sum){
	if(u>n){
		ans=max(ans,sum);
		return;
	}
	if(x+1<=n/2) dfs(u+1,x+1,y,z,sum+e[u].a);
	if(y+1<=n/2) dfs(u+1,x,y+1,z,sum+e[u].b);
	if(z+1<=n/2) dfs(u+1,x,y,z+1,sum+e[u].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		bool f=1,f1=1;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			if(e[i].b!=0 || e[i].c!=0) f=0;
			if(e[i].c!=0) f1=0;
		}
		if(f){
			sort(e+1,e+n+1,cmp1);
			reverse(e+1,e+n+1);
			for(int i=1;i<=n/2;i++) ans+=e[i].a;
			cout<<ans;
			return 0;
		}
		if(f1){
			int num=0;
			sort(e+1,e+n+1,cmp1);
			for(int i=1;i<=n/2;i++) num+=e[i].a;
			for(int i=n/2+1;i<=n;i++) num+=e[i].b;
			ans=max(ans,num);
			num=0;
			sort(e+1,e+n+1,cmp2);
			for(int i=1;i<=n/2;i++) num+=e[i].b;
			for(int i=n/2+1;i<=n;i++) num+=e[i].a;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
