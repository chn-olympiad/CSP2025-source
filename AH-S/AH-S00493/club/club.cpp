#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long a[200000][4],t,v,g[4],z[maxn],pos;
bool cp;
long long dp[4][201][201];
struct sd{
	long long e,y,z,k;
};
sd cn[maxn];
bool cmp(sd l,sd r){
	if(l.e==r.e){
		if(l.y==r.y){
			return l.z>r.z;
		}else{
			return l.y>r.y;
		}
	}else{
		return l.e>r.e;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	cin>>t;
	while(t--){
		long long n,m;
		pos=0;
		cp=0;
		memset(g,0,sizeof(g));
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(z,0,sizeof(z));
		cin>>m;
		n=m;
		for(int i=1;i<=m;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			cn[i].e=a[i][1];
			cn[i].y=a[i][2];
			cn[i].z=a[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int f=1;f<=n/2;f++){
					for(int p=1;p<=3;p++){
						dp[j][i][f]=max(dp[j][i][f],dp[j][i-1][f-1]+a[i][j]);
					}
				}
			}
		}
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=3;j++){
				pos=max(pos,dp[j][n][i]);
			}
		}
		cout<<pos;
	}
	return 0;
}
