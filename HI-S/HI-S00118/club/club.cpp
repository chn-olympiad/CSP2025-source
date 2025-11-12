#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int dp[1000][1000];
int ans[100010];
int n;
bool cmp(int a,int b){
	return a>b;
}
void num(){
	for(int i=1;i<=n;i++){
		ans[i]=a[i][1];
	}
	sort(ans+1,ans+1+n,cmp);
	int sum=0;
	for(int i=1;i<=n/2;i++){
		sum+=ans[i];
	}
	cout <<sum<<endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	for(int s=1;s<=t;s++){
		cin>>n;
		bool f=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][2]!=0||a[i][3]!=0){
					f=1;
				}
			}
		}
		if(f==0){
			num();
			break;
		}
		dp[0][0]=0;
		int num=n/2;
		for(int i=1;i<=n;i++){
			int new_dp[100][100];
			for(int x=0;x<=num;x++){
				for(int y=0;y<=num;y++){
					if(x+1<=num) new_dp[x+1][y]=max(new_dp[x+1][y],dp[x][y]+a[i][1]);
					if(y+1<=num) new_dp[x][y+1]=max(new_dp[x][y+1],dp[x][y]+a[i][2]);
					if((i-x-y)<=num)new_dp[x][y]=max(new_dp[x][y],dp[x][y]+a[i][3]);
				}
			}
			for(int x=0;x<=num;x++){
				for(int y=0;y<=num;y++){
					dp[x][y]=new_dp[x][y];
					new_dp[x][y]=0;
				}
			}
		}
		int maxx=-1;
		for(int x=0;x<=num;x++){
			for(int y=0;y<=num;y++){
				if((n-x-y)<=num) maxx=max(maxx,dp[x][y]);
			}
		}
		cout <<maxx<<endl;
		for(int x=0;x<=num;x++){
			for(int y=0;y<=num;y++){
				dp[x][y]=0;
			}
		}
	}
	return 0;
}

