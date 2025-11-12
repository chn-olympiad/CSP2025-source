#include <bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int a,b,c;
};
node d[100005];
int ma=0;
void dfs(int x,int ans,int p,int q,int l){
	int cn=ma;
	if(ma<ans){
		ma=ans;
//		cout<<ma<<endl;
	}
	if(p>n/2||q>n/2||l>n/2||x>n){
		ma=cn;
//		cout<<p<<' '<<q<<' '<<l<<' ';
		return ;
	}
//	cout<<ans<<' ';
	
	dfs(x+1,ans+d[x].a,p+1,q,l);
//	cout<<endl;
	dfs(x+1,ans+d[x].b,p,q+1,l);
//	cout<<endl;
	dfs(x+1,ans+d[x].c,p,q,l+1);
//	cout<<endl;
	return ;
}
int main () {
	cin>>t;
	while(t--){
		ma=0;
//	freopen ("club.in","r",stdin);
//	freopen ("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i].a >>d[i].b >>d[i].c;	
	}
	n++;
	dfs(1,0,0,0,0);
	cout<<ma<<endl;
}
	return 0;
}
