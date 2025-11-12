#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n;
int arr[N][3];
int dp[205][205][205];//remind!!
bool f1,f2;//
int prr[N];//A
struct node{//B
	int p,num1;
}prr2[N];
int ans=0;
bool cmp(node a,node b){
	return a.p>b.p;
}
void solved(){
	ans=0;
	f1=1;f2=1;memset(prr,0,sizeof(prr));//
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int w=0;w<=n/2;w++){
				dp[i][j][w]=0;
			}
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
		if(arr[i][1]!=0) f1=0;//
		if(arr[i][2]!=0) f2=0;//
	}
	
	if(f1&&f2){//
		for(int i=1;i<=n;i++) prr[i]=arr[i][0];
		sort(prr+1,prr+n+1);
		for(int i=n;i>n/2;i--) ans+=prr[i];
		printf("%d\n",ans);
		return ;
	}
	if(f2){//
		for(int i=1;i<=n;i++){
			prr2[i].p=arr[i][0]-arr[i][1];
			prr2[i].num1=arr[i][1];
		}
		sort(prr2+1,prr2+n+1,cmp);
		for(int i=1;i<=n/2;i++) ans+=prr2[i].p+prr2[i].num1;
		for(int i=n/2+1;i<=n;i++) ans+=prr2[i].num1;
		printf("%d\n",ans);
		return ;
	}
	
	for(int i=1;i<=n;i++){
		for(int b=n/2;b>=0;b--){
			for(int c=n/2;c>=0;c--){
				for(int d=n/2;d>=0;d--){
					int x,y,z;
					if(b==0) x=-1;
					else x=dp[b-1][c][d]+arr[i][0];
					if(c==0) y=-1;
					else y=dp[b][c-1][d]+arr[i][1];
					if(d==0) z=-1;
					else z=dp[b][c][d-1]+arr[i][2];
					
					dp[b][c][d]=max(x,max(y,z));
					if(i==n) ans=max(ans,dp[b][c][d]);
				}
			}
		}
	}
	printf("%d\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solved();
	return 0;
}
/*
I WANT 100TPS BUT I CAN ONLY GET 60
*/ 
