#include <bits/stdc++.h>
using namespace std;
int a[6000];
int vis[6000];
int yh[6000][6000];
int zong=0;int ans=0;int n;int mx;
bool cmp(int a,int b){
	return a<b;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3) {
		cout<<0;return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		zong+=a[i];
	} 
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	if(n==3){
		if(zong>2*mx) ans++;
	}
	if(n>3){
		int yi=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) yi++;
		}
		if(yi==n){
			yh[1][1]=1;
			for(int i=2;i<=n;i++){
				yh[i][1]=1;
				yh[i][i]=1;
			}
			for(int i=2;i<=n+1;i++){
				for(int j=2;j<=i;j++)
					yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
			}
			for(int l=4;l<=n+1;l++){
				ans+=yh[n+1][l];
			}
		}
		if(yi!=n){
			yh[1][1]=1;
			for(int i=2;i<=n;i++){
				yh[i][1]=1;
				yh[i][i]=1;
			}
			for(int i=2;i<=n+1;i++){
				for(int j=2;j<=i;j++)
					yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
			}
			for(int l=4;l<=n+1;l++){
				ans+=yh[n+1][l];
			}
		}
	}
	ans=ans%998244353;
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
