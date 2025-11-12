#include<bits/stdc++.h>
using namespace std;
int t;
int n,maxs;
int a[205][4] ;
int dp[205][105][205];
int Ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxs=n/2;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n<=200){
			memset(dp,0,sizeof dp);
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,maxs);j++){
					for(int k=0;k<=min(i-j,maxs);k++){
						if(i-j-k<=maxs){
							if(j+k<i)
								dp[i][j][k]=dp[i-1][j][k]+a[i][3];
							if(j>0)
								dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
							if(k>0)
								dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
						}
					}
				}
			}
			for(int i=0;i<=maxs;i++)
				for(int j=0;j<=min(n-i,maxs);j++)
					Ans=max(Ans,dp[n][i][j]);
			cout<<Ans<<"\n";
			Ans=0;
		}
		else{
			bool f=true;
			for(int i=1;i<=n;i++)
				if(a[i][2]!=0 or a[i][3]!=0)
					f=false;
			if(f){
				vector<int>cf;
				for(int i=1;i<=n;i++)
					cf.push_back(a[i][1]);
				sort(cf.begin(),cf.end(),greater<int>());
				for(int i=0;i<maxs;i++)
					Ans+=cf[i];
				cout<<Ans<<"\n";
				Ans=0;
			}
			else{
				int cnt1=0;
				int cnt2=0;
				priority_queue<int>q1;
				priority_queue<int>q2;
				for(int i=1;i<=n;i++){
					if(a[i][1]>a[i][2]){
						if(cnt1<maxs){
							cnt1++;
							q1.push(i);
							Ans+=a[i][1];
						}
						else{
							int j=q1.top();
							if(a[i][1]>a[j][1]){
								q1.pop();
								q1.push(i);
								Ans+=a[i][1];
								Ans-=a[j][1];
								Ans+=a[j][2];
							}
						}
					}
					else{
						if(cnt2<maxs){
							cnt2++;
							q1.push(i);
							Ans+=a[i][2];
						}
						else{
							int j=q2.top();
							if(a[i][2]>a[j][2]){
								q2.pop();
								q1.push(i);
								Ans+=a[i][2];
								Ans-=a[j][2];
								Ans+=a[j][1];
							}
						}
					}
				}
			}
			cout<<Ans<<"\n";
			Ans=0;
		}
	}
	return 0;
}
