#include<bits/stdc++.h>
using namespace std;
int n,t,m[4],ans,dp[100005];
int re[4];
struct people{
	int a,b,c,id,sum,sum1;
}e[100005];
bool cmp(people u,people v){
	if(u.sum==v.sum)return u.sum1>v.sum1;
	return u.sum>v.sum;
}
void ero(){
	for(int i=1;i<=n;i++){
		int o=e[i].id;
		if(m[1]==n/2&&o==1||m[2]==n/2&&o==2||m[3]==n/2&&o==3){
			if(e[re[o]].sum+e[i].sum1<e[re[o]].sum1+e[i].sum){
				dp[i]=e[re[o]].sum1+e[i].sum+dp[i-2];
				re[o]=i;
			}else{
				dp[i]=e[re[o]].sum+e[i].sum1+dp[i-2];
			}
		}else {
			re[o]=i;
			dp[i]=dp[i-1]+e[i].sum;
			m[o]++;
		}
	}
	return ;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0,re[1]=0,re[2]=0,re[3]=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>e[i].a>>e[i].b>>e[i].c;
			e[i].sum=max(e[i].a,max(e[i].b,e[i].c));
			if(e[i].sum==e[i].a){
				e[i].id=1;
				e[i].sum1=max(e[i].b,e[i].c);
			}else if(e[i].sum==e[i].b){
				e[i].id=2;
				e[i].sum1=max(e[i].a,e[i].c);
			}else if(e[i].sum==e[i].c){
				e[i].id=3;
				e[i].sum1=max(e[i].b,e[i].a);
			}
		}
		sort(e+1,e+1+n,cmp);
		ero();
		cout<<dp[n]<<endl;
	}
	return 0;
}
