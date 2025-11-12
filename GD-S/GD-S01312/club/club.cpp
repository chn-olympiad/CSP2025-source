#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
struct myd{
	int a,b,c;
}m[100010];
void dp(int a1,int b1,int c1,int s){
	if(a1>n/2||b1>n/2||c1>n/2)return;
	if(a1+b1+c1==n){
		ans=max(ans,s);
		return;
	}
	dp(a1+1,b1,c1,s+m[a1+b1+c1+1].a);
	dp(a1,b1+1,c1,s+m[a1+b1+c1+1].b);
	dp(a1,b1,c1+1,s+m[a1+b1+c1+1].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>m[i].a>>m[i].b>>m[i].c;
		dp(0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
