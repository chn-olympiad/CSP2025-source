#include<bits/stdc++.h>
using namespace std;
int n,a[100010][4],t,b[100010][3],dp[100010],c[4],ans,l,r,m;
int findx(int i){
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
		return 1;
	}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
		return 2;
	}else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
		return 3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				b[a[i][j]][j]++;
			}
			c[findx(i)]++;
			ans+=a[i][findx(i)];
		}
		for(int i=1;i<=3;i++){
			if(c[i]<=n/2) continue;
			else{
				m=i;
			}
		}
		if(m==1) l=2,r=3;
		else if(m==2) l=1,r=3;
		else if(m==3) l=1,r=2;
//		cout<<m<<" "<<l<<" "<<r<<"\n";
		if(m==0){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i][m]==max(a[i][m],max(a[i][l],a[i][r])))
				dp[a[i][m]-max(a[i][l],a[i][r])]++;
		}
		for(int i=0;i<=2e4;i++){
			while(dp[i]){
				dp[i]--;
				ans-=i;
				c[m]--;
				if(c[m]<=n/2) break;
			}
			if(c[m]<=n/2) break;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}