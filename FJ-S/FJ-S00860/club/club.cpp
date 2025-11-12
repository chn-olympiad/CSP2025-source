#include<bits/stdc++.h>
using namespace std;
const int N=210;
int f[N][N][N];
int a[N*500],b[N*500],c[N*500];
int n,t;
void dp(){
	memset(f,-128,sizeof(f));
	f[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(j+k>i) continue;
				if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i]);
				if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+b[i]);
				if(j+k<=i&&i-j-k<=n/2) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+c[i]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			ans=max(ans,f[n][i][j]);
		}
	}
	cout<<ans<<endl;
	return ;
}
void A(){
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>n/2;i--) ans+=a[i];
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		int flag=1;
		for(int i=1;i<=n;i++){
			if(b[i]>0||c[i]>0){
				flag=0;
				break;
			}
		}
		if(flag) A();
		else dp();
	}
	return 0;
}
