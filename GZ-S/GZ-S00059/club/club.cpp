//GZ-S00059 贵阳市南明区华麟学校 刘泽君雨 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans=0;
struct node{
	int a,b,c;
}p[N];
void dfs(int step,int cnt1,int cnt2,int cnt3,int sum){
	if(cnt1==n/2+1||cnt2==n/2+1||cnt3==n/2+1){
		return ;
	}
	if(step==n+1){
		ans=max(ans,sum);
		return ;
	}
	dfs(step+1,cnt1+1,cnt2,cnt3,sum+p[step].a);
	dfs(step+1,cnt1,cnt2+1,cnt3,sum+p[step].b);
	dfs(step+1,cnt1,cnt2,cnt3+1,sum+p[step].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 
