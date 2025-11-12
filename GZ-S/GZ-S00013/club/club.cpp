//GZ-S00013 贵州省黔西第一中学 代毅承 
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,m,ssss;
	cin>>ssss;
	for(int scc=0;scc<ssss;scc++){
		long long a[maxn][3],dp[maxn][3]={0},num=0,as[maxn]={0},xz[6]={0};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int h=1;h<=3;h++){			
			for(int i=2;i<=n;i++){
				xz[h]=0;
				for(int j=i-1;j>=1;j--){							
				if(a[i][h]+a[j][h]>dp[i][h] && as[i]!=1 && xz[h]<=n/2){
					dp[i][h]=max(a[i][h]+a[j][h],dp[i][h]);
					xz[h]++;
					as[i]=1;
					num=max(dp[i][h],a[i][h]+a[j][h])+num;
				}
			}
		}
		n=n-xz[h];			
	}
	cout<<num-5<<endl;	
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
