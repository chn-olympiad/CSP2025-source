#include <bits/stdc++.h>
using namespace std;
int t,n,f[205][205][205];
struct node{
	int x,y,z,c;
}a[100005];
bool cmp1(node a,node b){
	if(a.x!=b.x) return a.x>b.x;
	return a.y>b.y;
}
bool cmp2(node a,node b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool fa=1,fb=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].c=a[i].y-a[i].x;
			if(a[i].y||a[i].z) fa=0;
			if(a[i].z) fb=0;
		}
		if(fa){
			int ans=0;
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			cout<<ans<<"\n";
		}
		else if(fb){
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=a[i].x;
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].c;
			cout<<ans<<"\n";
		}
		else{
			int ans=0;
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=n/2;k++){
						int p=i-j-k;
						if(p>n/2) continue;
						if(p) f[i][j][k]=f[i-1][j][k]+a[i].z;
						if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].x);
						if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].y);
					}
				}
			}		
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					int p=n-i-j;
					if(p<=n/2) ans=max(ans,f[n][i][j]);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
