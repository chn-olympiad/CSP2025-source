#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct cl{
	long long bh,a,b,c;
}x[1000005];
void dfs(long long y,long long sum,long long aa,long long bb,long long cc){
	if(y>n||aa>n/2||bb>n/2||cc>n/2)return;
	ans=max(ans,sum);
	dfs(y+1,sum+x[y+1].a,aa+1,bb,cc);
	dfs(y+1,sum+x[y+1].b,aa,bb+1,cc);
	if(x[y+1].c>0)dfs(y+1,sum+x[y+1].c,aa,bb,cc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(long long i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}//Ren5Jie4Di4Ling5%
