#include<bits/stdc++.h>
using namespace std;
struct ps{
	int s1,s2,s3;
};
int dp[100001][3]={};
int jl[100001][3][3]={};
bool cmp(ps a,ps b){
	return a.s1<b.s1||(a.s1==b.s1&&a.s2<b.s2)||(a.s1==b.s1&&b.s2==a.s2&&a.s3<b.s3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		ps v[n];
		bool t[n];
		bool allb=true,allc=true;
		int pq[n];
		for(int i=0;i<n;i++){
			cin>>v[i].s1>>v[i].s2>>v[i].s3;
			if(v[i].s2!=0) allb=false;
			if(v[i].s3!=0) allc=false;
			if(v[i].s1<v[i].s2) pq[i]=2;
			if(v[i].s1>v[i].s2) pq[i]=1;
			if(v[i].s1==v[i].s2) pq[i]=0;
		}
		if(allb and allc){
			int y[n];
			for(int o=0;o<n;o++) y[o]=v[o].s1;
			sort(y,y+n);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=y[i-1];
			}
			cout<<ans<<endl;
		}
		else{
			memset(dp,0,sizeof(dp));
			memset(jl,0,sizeof(jl));
			sort(v,v+n,cmp);
			dp[0][0]=v[0].s1;
			dp[0][1]=v[0].s2;
			dp[0][2]=v[0].s3;
			jl[0][0][0]=1;
			jl[0][1][1]=1;
			jl[0][2][2]=1;
			for(int i=1;i<n;i++){
				for(int j=0;j<3;j++){
					int ks;
					if(j==0) ks=v[i].s1;
					if(j==1) ks=v[i].s2;
					if(j==2) ks=v[i].s3;
					for(int r=0;r<3;r++){
						if(jl[i-1][r][j]<n/2 and dp[i-1][r]+ks>dp[i][j]){
							dp[i][j]=dp[i-1][r]+ks;
							for(int l=0;l<3;l++) jl[i][j][l]=jl[i-1][r][l]+1;
						}
					}
					
				}
			}
			//cout<<endl;
			int ans=-1;
			for(int j=0;j<3;j++) ans=max(dp[n-1][j],ans);
			cout<<ans;
			cout<<"\n";
			//cout<<endl;
			//cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
		}
		
	}
	
	return 0;
} 
