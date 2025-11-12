#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int ans;
struct node{
	int a,b,c;
}s[100005];
void dfs(int d,int sum,int ca,int cb,int cc){
	if(d>n){
		ans=max(ans,sum);
		return ;
	}
	if(ca+1<=n/2)
		dfs(d+1,sum+s[d].a,ca+1,cb,cc);
	if(cb+1<=n/2)
		dfs(d+1,sum+s[d].b,ca,cb+1,cc);
	if(cc+1<=n/2)
		dfs(d+1,sum+s[d].c,ca,cb,cc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		if(n==1) ans=max(s[1].a,max(s[1].b,s[1].c));
		else dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
