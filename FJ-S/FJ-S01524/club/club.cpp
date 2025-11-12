#include<bits/stdc++.h>
using namespace std;
long long n,t,a[100005],b[100005],c[100005],sum1=0,dp[35][35][35][35];
long long maxn=0;
struct node{
	int num,d,num1;
}s[300005];
bool cmp(node x,node y){
	return x.d>y.d;
}
void dfs(int k,int s,int d,int f,long long sum){
	if(k==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(s>0){
		dfs(k+1,s-1,d,f,sum+a[k]);
	}
	if(d>0){
		dfs(k+1,s,d-1,f,sum+b[k]);
	}
	if(f>0){
		dfs(k+1,s,d,f-1,sum+c[k]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		maxn=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			s[(j-1)*3+1].d=a[j],s[(j-1)*3+2].d=b[j],s[(j-1)*3+3].d=c[j];
			s[(j-1)*3+1].num=j;
			s[(j-1)*3+1].num1=1;
			s[(j-1)*3+2].num=j;
			s[(j-1)*3+2].num1=2;
			s[(j-1)*3+3].num=j;
			s[(j-1)*3+3].num1=3;
		}
		if(n<=5){
			dfs(0,n/2,n/2,n/2,0);
			cout<<maxn<<endl;
		}else if(n<=35&&n>=5){
			dp[0][n/2][n/2][n/2]=0;
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					for(int s=0;s<=n;s++){
						for(int f=0;f<=n;f++){
							dp[j][k][s][f]=0;
						}
					}
				}
			}
			for(int s=1;s<=n;s++){
				for(int j=n/2;j>=0;j--){
					for(int k=n/2;k>=0;k--){
						for(int h=n/2;h>=0;h--){
							dp[s][j-1][k][h]=max(dp[s][j-1][k][h],dp[s-1][j][k][h]+a[s]);
							dp[s][j][k-1][h]=max(dp[s][j][k-1][h],dp[s-1][j][k][h]+b[s]);
							dp[s][j][k][h-1]=max(dp[s][j][k][h-1],dp[s-1][j][k][h]+c[s]);
						}
					}
				}
			}
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					for(int h=0;h<=n/2;h++){
						maxn=max(maxn,dp[n][j][k][h]);
					}
				}
			}
			cout<<maxn<<endl;
		}else{
			int e[3*n+20]={},k=n/2,l=n/2,m=n/2;
			sort(s+1,s+3*n+1,cmp);
			for(int j=1;j<=3*n;j++){
				if(!e[s[j].num]){
					if(s[j].num1==1){
						if(k>0){
							k--;
							sum1+=s[j].d;
							e[s[j].num]=1;
						}
					}else if(s[j].num1==2){
						if(l>0){
							l--;
							sum1+=s[j].d;
							e[s[j].num]=1;
						}
					}else if(s[j].num1==3){
						if(m>0){
							m--;
							sum1+=s[j].d;
							e[s[j].num]=1;
						}
					}
				}
			}
			cout<<sum1<<endl;
		}		
	}
	return 0;
}

