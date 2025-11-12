#include<bits/stdc++.h>
using namespace std;
struct B{
	int num,id;
}B1[100005],B2[100005];
bool cmp(B a,B b){
	return a.num>b.num;
}
int t,n,num[100005][4],up,ans,A[100005];
int cnt1,cnt2;
bool flag1,flag2,flag3;
void dfs(int k,int a,int b,int c,int sum){
	if(a>up||b>up||c>up) return;
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(k+1,a+1,b,c,sum+num[k][1]); 
	dfs(k+1,a,b+1,c,sum+num[k][2]); 
	dfs(k+1,a,b,c+1,sum+num[k][3]); 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-1;
		flag1=1,flag2=1,flag3=1;
		scanf("%d",&n);
		up=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&num[i][1],&num[i][2],&num[i][3]);
			if(num[i][1]!=0) flag1=0;
			if(num[i][2]!=0) flag2=0;
			if(num[i][3]!=0) flag3=0;
		} 
		if(n<=14){
			ans=-1;
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
		}
		else if(flag1==0&&flag2==1&&flag3==1){
			ans=0;
			for(int i=1;i<=n;i++) A[i]=num[i][1];
			sort(A+1,A+1+n);
			for(int i=up+1;i<=n;i++) ans+=A[i];
			printf("%d\n",ans);
		}
		else{
			ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(num[i][1],max(num[i][2],num[i][3]));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
