#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=1e5+5;
struct add{
	int a1,b1,c1;
}a[N];
bool cmp(add a,add b){
	return a.a1>b.a1;
}
struct aee{
	int s,a1,a2,a3;
}dp[N][4];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ok=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].b1>>a[i].c1;
			if(a[i].b1!=0 or a[i].c1!=0){
				ok=0;
			}
		}
		int sum=0;
		if(ok==1){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].a1;
			}
			cout<<sum<<endl;
		}else{
			for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j].s=0;
				dp[i][j].a1=0;
				dp[i][j].a2=0;
				dp[i][j].a3=0;
			}
		}
		for(int i=1;i<=n;i++){
			int x=dp[i-1][1].s+a[i].a1,y=dp[i-1][2].s+a[i].a1,z=dp[i-1][3].s+a[i].a1;
			if(dp[i-1][1].a1>=n/2){
				x=0;
			}
			if(dp[i-1][2].a1>=n/2){
				y=0;
			}
			if(dp[i-1][3].a1>=n/2){
				z=0;
			}
			dp[i][1].s=max({x,y,z});
			if(dp[i][1].s==x){
				dp[i][1].a1=dp[i-1][1].a1;
				dp[i][1].a2=dp[i-1][1].a2;
				dp[i][1].a3=dp[i-1][1].a3;
				dp[i][1].a1=dp[i-1][1].a1+1;
			}
			else{
				 if(dp[i][1].s==y){
				 				dp[i][1].a1=dp[i-1][2].a1;
				                dp[i][1].a2=dp[i-1][2].a2;
				                dp[i][1].a3=dp[i-1][2].a3;
				 				dp[i][1].a1=dp[i-1][2].a1+1;
				 }
				 else if(dp[i][1].s==z){
				 	dp[i][1].a1=dp[i-1][3].a1;
					dp[i][1].a2=dp[i-1][3].a2;
					dp[i][1].a3=dp[i-1][3].a3;
				 	dp[i][1].a1=dp[i-1][3].a1+1;
				 }
			}
			x=dp[i-1][1].s+a[i].b1,y=dp[i-1][2].s+a[i].b1,z=dp[i-1][3].s+a[i].b1;
			if(dp[i-1][1].a2>=n/2){
				x=0;
			}
			if(dp[i-1][2].a2>=n/2){
				y=0;
			}
			if(dp[i-1][3].a2>=n/2){
				z=0;
			}
			dp[i][2].s=max({x,y,z});
			if(dp[i][2].s==x){
				dp[i][2].a1=dp[i-1][1].a1;
				dp[i][2].a2=dp[i-1][1].a2;
				dp[i][2].a3=dp[i-1][1].a3;
				dp[i][2].a2=dp[i-1][1].a2+1;
			}
			else{
				if(dp[i][2].s==y){
					dp[i][2].a1=dp[i-1][2].a1;
					dp[i][2].a2=dp[i-1][2].a2;
					dp[i][2].a3=dp[i-1][2].a3;
					dp[i][2].a2=dp[i-1][2].a2+1;
				}
				else if(dp[i][2].s==z){
					dp[i][2].a1=dp[i-1][3].a1;
					dp[i][2].a2=dp[i-1][3].a2;
					dp[i][2].a3=dp[i-1][3].a3;
					dp[i][2].a2=dp[i-1][3].a2+1;
				}
			}
			x=dp[i-1][1].s+a[i].c1,y=dp[i-1][2].s+a[i].c1,z=dp[i-1][3].s+a[i].c1;
			if(dp[i-1][1].a3>=n/2){
				x=0;
			}
			if(dp[i-1][2].a3>=n/2){
				y=0;
			}
			if(dp[i-1][3].a3>=n/2){
				z=0;
			}
			dp[i][3].s=max({x,y,z});
			if(dp[i][3].s==x){
				dp[i][3].a1=dp[i-1][1].a1;
				dp[i][3].a2=dp[i-1][1].a2;
				dp[i][3].a3=dp[i-1][1].a3;
				dp[i][3].a3=dp[i-1][1].a3+1;
			}
			else{
				 if(dp[i][3].s==y){
				 	dp[i][3].a1=dp[i-1][2].a1;
					dp[i][3].a2=dp[i-1][2].a2;
					dp[i][3].a3=dp[i-1][2].a3;
				 	dp[i][3].a3=dp[i-1][2].a3+1;
				 }
				else if(dp[i][3].s==z){
					dp[i][3].a1=dp[i-1][3].a1;
					dp[i][3].a2=dp[i-1][3].a2;
					dp[i][3].a3=dp[i-1][3].a3;
					dp[i][3].a3=dp[i-1][3].a3+1;
				}
			}
		}
		int s=max({dp[n][1].s,dp[n][2].s,dp[n][3].s});
		cout<<s<<endl;
		}	
	}
	return 0;
} 