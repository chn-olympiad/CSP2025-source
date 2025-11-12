#include<bits/stdc++.h>
using namespace std;
int n,t,ans;
int a[10012][4],b1[10012],b2[10012],b3[10012];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int y=1; y<=t; y++) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++)for(int j=1; j<=3; j++)scanf("%d",&a[i][j]);
		for(int i=1; i<=n; i++) {
			b1[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			b3[i]=min(min(a[i][1],a[i][2]),a[i][3]);
			for(int j=1; j<=3; j++)if(a[i][j]==b1[i])a[i][j]=0,b2[i]=max(max(a[i][1],a[i][2]),a[i][3]),a[i][j]=b1[i];
			if(n==2)ans=max(max(max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),a[1][2]+a[2][1]),a[1][2]+a[2][3]),a[1][3]+a[2][1]),a[1][3]+a[2][2]);
		}
		cout<<ans<<"\n";
	}
}
