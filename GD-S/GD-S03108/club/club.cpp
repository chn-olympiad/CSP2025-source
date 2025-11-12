#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool ff,fff;
struct s {
	int x,y,z;
} a[1000];
int t,n,f[1000][700][700],maxx;
bool cmp(s a,s b){
	return a.x>b.x;
}
bool cmp1(s a,s b){
	return a.x-a.y>b.x-b.y;
}
int main() {
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		maxx=0;
		memset(f,0,sizeof f);
		fff=false;
		ff=false;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0)fff=true;
			if(a[i].z!=0)ff=true;
		}
		if(!fff){
			long long ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		if(!ff){
			long long ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans+=a[i].x;
				else ans+=a[i].y;
			}
			cout<<ans<<endl;
			continue;
		}
		f[1][1][0]=a[1].x;
		f[1][0][1]=a[1].y;
		f[1][0][0]=a[1].z;
		//sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=min(n/2,i); j++) {
				for(int k=0;k<=min(n/2,i-j); k++) {
					if(k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].y);
					if(j>0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].x);
					if(i-j-k>=1)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
				}
			}
		}
		for(int i=1; i<=n/2; i++) {
			for(int j=1; j<=n/2; j++) {
				maxx=max(maxx,f[n][i][j]);
			}
		}
		cout<<maxx<<endl;
/*
5
200
*/
	}
	return 0;
}
