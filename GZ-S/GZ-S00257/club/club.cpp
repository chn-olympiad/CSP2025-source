//GZ-S00257 贵州省凯里市第一中学 杨再尧 
#include<bits/stdc++.h>
using namespace std;

int ans=-1;
int a[100005][3];
int n;
void dfs(int i,int cnt1,int cnt2,int cnt3,int sum){
	if(i=n)ans=max(ans,sum);
	for(int j=0;j<3;j++){
		if(j==0 && cnt1<n/2)dfs(i+1,cnt1+1,cnt2,cnt3,sum+a[i][j]);
		else if(j==1 && cnt2<n/2)dfs(i+1,cnt1,cnt2+1,cnt3,sum+a[i][j]);
		else if(j==2 && cnt3<n/2)dfs(i+1,cnt1,cnt2,cnt3+1,sum+a[i][j]);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]);
		}
		dfs(0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
