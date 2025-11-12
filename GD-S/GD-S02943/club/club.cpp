#include<bits/stdc++.h>
using namespace std;
int n,t,dp[500005][3],a1[500005][3],b1[500005][3],c1[500005][3],num,a2,b2,c2;
struct Node{
	int a,b,c;
}m[500005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(m,0,sizeof(m));
		memset(dp,0,sizeof(dp));
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		memset(c1,0,sizeof(c1));
		scanf("%d",&n);
		num=n/2;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&m[i].a,&m[i].b,&m[i].c);
		for(int i=1;i<=n;i++){
			int flag1=0,flag2=0,flag3=0;
			if(dp[i-1][0]+m[i].a>=dp[i-1][1]+m[i].a && dp[i-1][0]+m[i].a>=dp[i-1][2]+m[i].a){
				if(a1[i-1][0]+1<=num){
					dp[i][0]=dp[i-1][0]+m[i].a;
					a1[i][0]=a1[i-1][0]+1;
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2];
					flag1=0;
				}else if(dp[i-1][1]+m[i].a>=dp[i-1][2]+m[i].a && a1[i-1][1]+1<=num){
					dp[i][0]=dp[i-1][1]+m[i].a;
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1]+1;
					a1[i][2]=a1[i-1][2];
					flag1=1;
				}else if(a1[i-1][2]+1<=num){
					dp[i][0]=dp[i-1][2]+m[i].a;
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2]+1;
					flag1=2;
				}else{
					dp[i][0]=dp[i-1][1];
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2];
					flag1=0;
				}
			}else if(dp[i-1][1]+m[i].a>=dp[i-1][2]+m[i].a){
				if(a1[i-1][1]+1<=num){
					dp[i][0]=dp[i-1][1]+m[i].a;
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1]+1;
					a1[i][2]=a1[i-1][2];
					flag1=1;
				}else if(dp[i-1][0]+m[i].a>=dp[i-1][2]+m[i].a && a1[i-1][0]+1<=num){
					dp[i][0]=dp[i-1][0]+m[i].a;
					a1[i][0]=a1[i-1][0]+1;
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2];
					flag1=0;
				}else if(a1[i-1][2]+1<=num){
					dp[i][0]=dp[i-1][2]+m[i].a;
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2]+1;
					flag1=2;
				}else{
					dp[i][0]=dp[i-1][0];
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2];
					flag1=0;
				}
			}else{
				if(a1[i-1][2]+1<=num){
					dp[i][0]=dp[i-1][2]+m[i].a;
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2]+1;
					flag1=2;
				}else if(dp[i-1][0]+m[i].a>=dp[i-1][1]+m[i].a && a1[i-1][0]+1<=num){
					dp[i][0]=dp[i-1][0]+m[i].a;
					a1[i][0]=a1[i-1][0]+1;
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2];
					flag1=0;
				}else if(a1[i-1][1]+1<=num){
					dp[i][0]=dp[i-1][1]+m[i].a;
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1]+1;
					a1[i][2]=a1[i-1][2];
					flag1=1;
				}else{
					dp[i][0]=dp[i-1][0];
					a1[i][0]=a1[i-1][0];
					a1[i][1]=a1[i-1][1];
					a1[i][2]=a1[i-1][2];
					flag1=0;
				}
			}
			cout<<dp[i][0]<<" "<<a1[i][0]<<" "<<a1[i][1]<<" "<<a1[i][2]<<" ";
			if(dp[i-1][0]+m[i].b>=dp[i-1][1]+m[i].b && dp[i-1][0]+m[i].b>=dp[i-1][2]+m[i].b){
				if(b1[i-1][0]+1<=num){
					dp[i][1]=dp[i-1][0]+m[i].b;
					b1[i][0]=b1[i-1][0]+1;
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2];
					flag2=0;
				}else if(dp[i-1][1]+m[i].b>=dp[i-1][2]+m[i].b && b1[i-1][1]+1<=num){
					dp[i][1]=dp[i-1][1]+m[i].b;
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1]+1;
					b1[i][2]=b1[i-1][2];
					flag2=1;
				}else if(b1[i-1][2]+1<=num){
					dp[i][1]=dp[i-1][2]+m[i].b;
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2]+1;	
					flag2=2;
				}else{
					dp[i][1]=dp[i-1][1];
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2];
					flag2=1;
				}
			}else if(dp[i-1][1]+m[i].b>=dp[i-1][2]+m[i].b){
				if(b1[i-1][1]+1<=num){
					dp[i][1]=dp[i-1][1]+m[i].b;
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1]+1;
					b1[i][2]=b1[i-1][2];
					flag2=1;
				}else if(dp[i-1][0]+m[i].b>=dp[i-1][2]+m[i].b && b1[i-1][0]+1<=num){
					dp[i][1]=dp[i-1][0]+m[i].b;
					b1[i][0]=b1[i-1][0]+1;
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2];
					flag2=0;
				}else if(b1[i-1][2]+1<=num){
					dp[i][1]=dp[i-1][2]+m[i].b;
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2]+1;	
					flag2=2;
				}else{
					dp[i][1]=dp[i-1][0];
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2];
					flag2=0;
				}
			}else{
				if(b1[i-1][2]+1<=num){
					dp[i][1]=dp[i-1][2]+m[i].b;
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2]+1;
					flag2=2;
				}else if(dp[i-1][0]+m[i].b>=dp[i-1][1]+m[i].b && b1[i-1][0]+1<=num){
					dp[i][1]=dp[i-1][0]+m[i].b;
					b1[i][0]=b1[i-1][0]+1;
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2];
					flag2=0;
				}else if(b1[i-1][1]+1<=num){
					dp[i][1]=dp[i-1][1]+m[i].b;
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1]+1;
					b1[i][2]=b1[i-1][2];
					flag2=1;
				}else{
					dp[i][1]=dp[i-1][0];
					b1[i][0]=b1[i-1][0];
					b1[i][1]=b1[i-1][1];
					b1[i][2]=b1[i-1][2];
					flag2=0;
				}
			}
			cout<<dp[i][1]<<" "<<b1[i][0]<<" "<<b1[i][1]<<" "<<b1[i][2]<<" ";
			if(dp[i-1][0]+m[i].c>=dp[i-1][1]+m[i].c && dp[i-1][0]+m[i].c>=dp[i-1][2]+m[i].c){
				if(c1[i-1][0]+1<=num){
					dp[i][2]=dp[i-1][0]+m[i].c;
					c1[i][0]=c1[i-1][0]+1;
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2];
					flag3=0;
				}else if(dp[i-1][1]+m[i].c>=dp[i-1][2]+m[i].c && c1[i-1][1]+1<=num){
					dp[i][2]=dp[i-1][1]+m[i].c;
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1]+1;
					c1[i][2]=c1[i-1][2];
					flag3=1;
				}else if(c1[i-1][2]+1<=num){
					dp[i][2]=dp[i-1][2]+m[i].c;
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2]+1;
					flag3=2;
				}else{
					dp[i][2]=dp[i-1][1];
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2];
					flag3=1;
				}
			}else if(dp[i-1][1]+m[i].c>=dp[i-1][2]+m[i].c){
				if(c1[i-1][1]+1<=num){
					dp[i][2]=dp[i-1][1]+m[i].c;
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1]+1;
					c1[i][2]=c1[i-1][2];
					flag3=1;
				}else if(dp[i-1][0]+m[i].c>=dp[i-1][2]+m[i].c && c1[i-1][0]+1<=num){
					dp[i][2]=dp[i-1][0]+m[i].c;
					c1[i][0]=c1[i-1][0]+1;
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2];
					flag3=0;
				}else if(c1[i-1][2]+1<=num){
					dp[i][2]=dp[i-1][2]+m[i].c;
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2]+1;
					flag3=2;
				}else{
					dp[i][2]=dp[i-1][0];
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2];
					flag3=0;
				}
			}else{
				if(c1[i-1][2]+1<=num){
					dp[i][2]=dp[i-1][2]+m[i].c;
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2]+1;
					flag3=2;
				}else if(dp[i-1][0]+m[i].c>=dp[i-1][1]+m[i].c && c1[i-1][0]+1<=num){
					dp[i][2]=dp[i-1][0]+m[i].c;
					c1[i][0]=c1[i-1][0]+1;
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2];
					flag3=0;
				}else if(c1[i-1][1]+1<=num){
					dp[i][2]=dp[i-1][1]+m[i].c;
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1]+1;
					c1[i][2]=c1[i-1][2];
					flag3=1;
				}else{
					dp[i][2]=dp[i-1][0];
					c1[i][0]=c1[i-1][0];
					c1[i][1]=c1[i-1][1];
					c1[i][2]=c1[i-1][2];
					flag3=0;
				}
			}
			cout<<dp[i][2]<<" "<<c1[i][0]<<" "<<c1[i][1]<<" "<<c1[i][2]<<endl;
			if(dp[i][0]>dp[i][1] && dp[i][1]>dp[i][2])a2=a1[i][flag1];
			else if(dp[i][1]>dp[i][2])b2=b1[i][flag2];
			else c2=c1[i][flag3];
		}
		printf("%d\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
