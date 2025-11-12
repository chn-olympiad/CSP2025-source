#include<bits/stdc++.h>
using namespace std;
bool flag;
bool flag1;
struct peo{
	int a,b,c;
	void input(){
		cin>>a>>b>>c;
		if(c != 0){
			flag = false;
		}if(b != 0 or c != 0){
			flag1 = false;
		}
		return;
	}
}p[100005];
bool cmp(peo aa,peo bb){
	return aa.a > bb.a ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t --){
		int n;
		cin>>n;
		flag=true;
		flag1=true;
		for(int i = 1;i <= n;i ++){
			p[i].input();
		}if(flag1){
			int ans =0 ;
			sort(p+1,p+1+n,cmp);
			for(int i = 1;i <= n/2;i ++){
				ans += p[i].a;
			}cout<<ans<<endl;
		}else if(flag){
			int temp = n/2+10;
			int dp[temp][temp],ans=INT_MIN;
			dp[0][0] = 0;
			for(int i = 0;i < temp;i ++){
				for(int j = 0;j < temp;j ++){
					dp[i][j] = 0;
				}
			}
			for(int i = 1;i <= n;i ++){
				for(int x = 0;x <= n/2;x ++){
					int y = i-x;
					if(y > n/2)continue;
					if(x>=1)dp[x][y] = max(dp[x][y],dp[x-1][y] + p[i].a);
					if(y>=1)dp[x][y] = max(dp[x][y],dp[x][y-1] + p[i].b);
					ans = max(dp[x][y],ans);
				}
			}cout<<ans<<endl;
		}else{
			int temp = n/2+10;
			int dp[temp][temp][temp],ans=INT_MIN;
			dp[0][0][0] = 0;
			for(int i = 0;i < temp;i ++){
				for(int j = 0;j < temp;j ++){
					for(int k = 0;k < temp;k ++){
							dp[i][j][k] = 0;
					}
				}
			}
			for(int i = 1;i <= n;i ++){
				for(int x = 0;x <= n/2;x ++){
					for(int y = 0;y <= n/2 and x + y <= i ;y ++){
						int z = i-x-y;
						if(z > n/2){
							continue;
						}
						if(x>=1)dp[x][y][z] = max(dp[x][y][z],dp[x-1][y][z] + p[i].a);
						if(y>=1)dp[x][y][z] = max(dp[x][y][z],dp[x][y-1][z] + p[i].b);
						if(z >= 1)dp[x][y][z] = max(dp[x][y][z],dp[x][y][z-1] + p[i].c);
						ans = max(dp[x][y][z],ans);
					}
				}
			}cout<<ans<<endl;
		}
	}
	
	return 0;
} 
