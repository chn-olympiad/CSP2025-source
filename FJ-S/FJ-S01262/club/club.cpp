#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5];
int dp[100005][5];
int cnt[5];
int mn[5];
int mnw[5];
int ans;
int x[100005];
int y[100005];
int z[100005];
int fx,fy,fz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		fx=0;
		fy=0;
		fz=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			x[++cnt[1]]=a[i][1];
			y[++cnt[2]]=a[i][2];
			z[++cnt[3]]=a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) fx=1;
			if(a[i][1]!=0||a[i][3]!=0) fy=1;
			if(a[i][2]!=0&&a[i][1]!=0) fz=1;
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(fx==0){
			sort(x+1,x+n+1);
			for(int i=1;i<=n/2;i++) ans-=x[i];
		}
		if(fy==0){
			sort(y+1,y+n+1);
			for(int i=1;i<=n/2;i++) ans-=y[i]; 
			
		}
		if(fz==0){
			sort(z+1,z+n+1);
			for(int i=1;i<=n/2;i++) ans-=z[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

