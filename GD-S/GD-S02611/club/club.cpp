#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
struct node{
	int x,y,z;
}a[N];
int mx=INT_MIN;
void dfs(int q,int b,int c,int dep,int sum){
	if(q>(n/2)||b>(n/2)||c>(n/2)) return ;
	if(dep==n+1){
		mx=max(mx,sum);
		return ;
	}
	dfs(q+1,b,c,dep+1,sum+a[dep].x);
	dfs(q,b+1,c,dep+1,sum+a[dep].y);
	dfs(q,b,c+1,dep+1,sum+a[dep].z);
}
//int dp[N][4][2];
int cmp2(node a,node b){
	if(a.y!=b.y) return a.y>b.y;
	else return a.x<b.x;
}
int cmp1(node a,node b){
	if(a.x!=b.x) return a.x>b.x;
	else a.y<b.y;
}
int num;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		mx=INT_MIN;
		int flag=0;
		num=0;
		int sum1=0,sum2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].z!=0) flag=1;
			if(a[i].x==0) num++;
			if(a[i].z==0) num++;
		}
		if(num==2*n){
			sort(a+1,a+n+1,cmp2);
			cout<<a[1].y+a[2].y<<endl;
		}else if(!flag){
			sort(a+1,a+n+1,cmp2);
			int ans=0;
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans+=a[i].x;
				}else{
					ans+=a[i].y;
				}
			}
			ans=0;
			mx=max(mx,ans);
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans+=a[i].x;
				}else{
					ans+=a[i].y;
				}
			}
			mx=max(ans,mx);
			cout<<mx<<endl;
		}else{
			dfs(0,0,0,1,0);
			cout<<mx<<endl;
		}
	}
return 0;
}
/*
3
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
*/

/*
1
4
2 1 0
1 2 0
2 3 0
3 2 0

*/


//			if(i==1){
//				dp[1][1][1]=a[i][1];
//				dp[1][2][1]=a[i][2];
//				dp[1][3][1]=a[i][3];
//				dp[1][1][2]=dp[1][2][2]=dp[1][3][2]=1;
//			}
//		}
//		cout<<endl;
//		for(int i=2;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				for(int k=1;k<=3;k++){
//					if(dp[i-1][j][2]+1<=(n/2)){
//						int t=dp[i][j][1];
//
//						dp[i][j][1]=max(dp[i-1][k][1]+a[i][j],dp[i][j][1]);
//						if(dp[i][j][1]!=t){
//							dp[i][j][2]=dp[i-1][k][2]+1;
//						}
//					}
//				}
//			}
//		}
//			
//		for(int i=1;i<=3;i++){
//			mx=max(mx,dp[n][i][1]);
//		}
//		cout<<mx<<endl;

/*
18:23
挺难的，感觉进不了noip，但是游记还是要写的

我是浦帅的忠实粉丝！！！！

东华高级中学十佳歌手比赛欧世博不应该被淘汰！！！ 

*/ 
