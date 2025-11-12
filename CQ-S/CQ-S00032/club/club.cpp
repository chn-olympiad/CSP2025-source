#include<bits/stdc++.h>
using namespace std;
struct node{int myd,dep,prs,zero;}arr[3000005];
bool cmp1(node a,node b){
	if(a.zero==b.zero) return a.myd>b.myd;
	return a.zero>b.zero;
}
bool cmp2(node a,node b){
	if(a.myd==b.myd) return a.zero>b.zero;
	return a.myd>b.myd;
}
int pep[100005],dpt[5];
int dp[105][105][105];
int aa[105],bb[105],cc[105];
int mx=0;
void dfs(int x,int n,int sum){
	if(x>n){
		mx=max(mx,sum);
		return;
	}
	if(dpt[1]<n/2){
		dpt[1]++;
		dfs(x+1,n,sum+aa[x]);
		dpt[1]--;
	}
	if(dpt[2]<n/2){
		dpt[2]++;
		dfs(x+1,n,sum+bb[x]);
		dpt[2]--;
	}
	if(dpt[3]<n/2){
		dpt[3]++;
		dfs(x+1,n,sum+cc[x]);
		dpt[3]--;
	}
}
void bf(int n){
	mx=0;
	dpt[1]=dpt[2]=dpt[3]=0;
	dfs(1,n,0);
	cout<<mx<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,cnt=0;
		cin>>n;
		dpt[1]=dpt[2]=dpt[3]=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			aa[i]=x,bb[i]=y,cc[i]=z;
			int zr=0;
			if(x==0) zr++;
			if(y==0) zr++;
			if(z==0) zr++;
			arr[++cnt]={x,1,i,zr};
			arr[++cnt]={y,2,i,zr};
			arr[++cnt]={z,3,i,zr};
			pep[i]=0;
		}
		if(n<=20){
			bf(n);
			continue;
		}
		sort(arr+1,arr+1+cnt,cmp1);
		int ans=0;
		for(int i=1;i<=cnt;i++){
			if(dpt[arr[i].dep]<n/2&&pep[arr[i].prs]==0){
				dpt[arr[i].dep]++,pep[arr[i].prs]=1;
				ans+=arr[i].myd;
			}
		}
		sort(arr+1,arr+1+n,cmp2);
		int ans2=0;
		for(int i=1;i<=n;i++) pep[i]=0;
		dpt[1]=dpt[2]=dpt[3]=0;
		for(int i=1;i<=cnt;i++){
			if(dpt[arr[i].dep]<n/2&&pep[arr[i].prs]==0){
				dpt[arr[i].dep]++,pep[arr[i].prs]=1;
				ans2+=arr[i].myd;
			}
		}
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=1;j--){
				for(int k=n/2;k>=1;k--){
					for(int l=n/2;l>=1;l--){
						dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+aa[i]);
						dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+bb[i]);
						dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+cc[i]);
					}
				}
			}
		}
		cout<<max(max(ans,ans2),dp[n/2][n/2][n/2])<<"\n";
	}

	return 0;
}
