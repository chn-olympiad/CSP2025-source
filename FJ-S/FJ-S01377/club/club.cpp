#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int T,n,f[205][205][205],ma,ans;
bool cmp(node x,node y){
	return x.y-x.x>y.y-y.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>a[i].x>>a[i].y>>a[i].z;
		if(n<=200){
			memset(f,0,sizeof f);
			ma=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=min(i,n/2);j++)
					for(int k=0;k<=min(i,n/2);k++){
						if(i-j-k>n/2||i<j+k)	continue;
						if(j)	f[i][j][k]=f[i-1][j-1][k]+a[i].x;
						if(k)	f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].y);
						if(i-j-k)	f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
					}
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=n/2;k++)
					if(n-j-k<=n/2)	ma=max(ma,f[n][j][k]);
			cout<<ma<<"\n";
			continue;
		}
		ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)	ans+=a[i].y;
		for(int i=n/2+1;i<=n;i++)	ans+=a[i].x;
		cout<<ans<<"\n";
	}
	return 0;
}
