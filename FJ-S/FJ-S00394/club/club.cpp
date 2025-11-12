#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
struct node{
	int a,b,c;
};
vector<node>num;
long long dp[N/2];
long long ans=0;
int n;
void dfs(int pos,int one,int two,int three,long long s){
	if(pos==n) {
		ans=max(ans,s);
		return;
	}
	if(one<n/2) dfs(pos+1,one+1,two,three,s+num[pos].a);
	if(two<n/2) dfs(pos+1,one,two+1,three,s+num[pos].b);
	if(three<n/2) dfs(pos+1,one,two,three+1,s+num[pos].c);
}
bool cmp(node x,node y){
	return x.a > y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		num.clear();
		ans=0;
		int flag=2;
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			num.push_back({a,b,c}); 
			if(b!=0 && flag) flag=1;
			if(c!=0) flag=0;
		}
		if(flag==2){
			sort(num.begin(),num.end(),cmp);
			for(int i=0;i<n/2;i++) ans+=num[i].a;
			cout<<ans;
			continue;
		}
		if(flag==1){
			memset(dp,0,sizeof(dp));
			for(int i=0;i<n;i++){
				for(int j=n/2;j>=0;j--){
					if(j==0){
						dp[j]+=num[i].a;
						continue;
					}
					dp[j]=max(dp[j]+num[i].a,dp[j-1]+num[i].b);
				}
			}
			for(int j=0;j<=n/2;j++){
				ans=max(ans,dp[j]);
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

