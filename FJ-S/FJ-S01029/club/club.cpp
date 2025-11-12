#include<bits/stdc++.h>

using namespace std;
int t,len,ans;
struct node{
	int a,b,c,maxn,maxid;
}f[100101];
bool cmp(node a,node b){
	return a.maxn>b.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof f);
		int dp[100001][5]={0},n,aa=0,bb=0,cc=0;
		cin>>n;
		f[n+1].a=f[n+1].b=f[n+1].c=f[n+1].maxid=f[n+1].maxn=ans=0;
		len=n/2;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			f[i].maxn=max(f[i].a,max(f[i].b,f[i].c));
			if(f[i].a==f[i].maxn)f[i].maxid=1;
			if(f[i].b==f[i].maxn)f[i].maxid=2;
			if(f[i].c==f[i].maxn)f[i].maxid=3;
		}
		sort(f+1,f+n+1,cmp);
		dp[1][1]=f[1].a;
		dp[1][2]=f[1].b;
		dp[1][3]=f[1].c;
		if(f[1].maxid==1)aa++;
		if(f[1].maxid==2)bb++;
		if(f[1].maxid==3)cc++;
		ans=f[1].maxn;
		for(int i=2;i<=n+1;i++){
			if(aa>=len){
				dp[i][1]=max(dp[i-1][2],dp[i-1][3])+f[i].a;
				dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].b;
				dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].c;
				ans=max(ans,max(dp[i][2],dp[i][3]));
				if(ans==dp[i][2]&&f[i].b!=0)bb++;
				else if(ans==dp[i][3]&&f[i].c!=0)cc++;
			}
			else if(bb>=len){
				dp[i][2]=max(dp[i-1][1],dp[i-1][3])+f[i].b;
				dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].a;
				dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].c;
				ans=max(ans,max(dp[i][1],dp[i][3]));
				if(ans==dp[i][1]&&f[i].a!=0)aa++;
				else if(f[i].c!=0)cc++;
			}
			else if(cc>=len){
				dp[i][3]=max(dp[i-1][1],dp[i-1][2])+f[i].c;
				dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].a;
				dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].b;
				ans=max(ans,max(dp[i][1],dp[i][2]));
				if(ans==dp[i][2]&&f[i].b!=0)bb++;
				else if(f[i].a!=0)aa++;
			}else{
				if(aa>=len)
					dp[i][1]=max(dp[i-1][2],dp[i-1][3])+f[i].a;
				else
					dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].a;
				if(bb>=len)
					dp[i][2]=max(dp[i-1][1],dp[i-1][3])+f[i].b;
				else
					dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].b;
				if(cc>=len)
					dp[i][3]=max(dp[i-1][1],dp[i-1][2])+f[i].c;
				else
					dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+f[i].c;
				if(aa>=len)
					ans=max(ans,max(dp[i][3],dp[i][2]));
				else if(bb>=len)
					ans=max(ans,max(dp[i][3],dp[i][1]));
				else if(cc>=len)
					ans=max(ans,max(dp[i][1],dp[i][2]));
				else
					ans=max(max(ans,dp[i][1]),max(dp[i][2],dp[i][3]));
				if(ans==dp[i][1]&&aa>=len){
					if(dp[i][2]>dp[i][3]){
						ans=dp[i][2];
						bb++;
					}else{
						ans=dp[i][3];
						cc++;
					}
				}
				else if(ans==dp[i][1]&&aa<len)aa++;
				else if(ans==dp[i][2]&&bb>=len){
					if(dp[i][1]>dp[i][3]){
						ans=dp[i][1];
						aa++;
					}else{
						ans=dp[i][3];
						cc++;
					}
				}
				else if(ans==dp[i][2]&&bb<len)bb++;
				else cc++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

out:
18
4
13
*/
