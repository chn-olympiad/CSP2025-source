#include<bits/stdc++.h>
using namespace std;
int n;
struct node {
	int a,b,c;
} p[100005];
int f[205][105][105][105];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=i; j++) {
				for(int k=0; k<=i; k++) {
					int lft=i-j-k;
					if(lft<0||lft>n/2||k>n/2||j>n/2) continue;
					f[i][j][k][lft]=0;
				}
			}
		}
		int ans=-1;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=i; j++) {
				for(int k=0; k<=i; k++) {
					int lft=i-j-k;
					if(lft<0||lft>n/2||k>n/2||j>n/2) continue;
					int x,y,z;
					if(j==0) x=f[i-1][j][k][lft];
					else x=f[i-1][j-1][k][lft]+p[i].a;
					
					if(k==0) y=f[i-1][j][k][lft];
					else y=f[i-1][j][k-1][lft]+p[i].b;
					
					if(lft==0) z=f[i-1][j][k][lft];
					else z=f[i-1][j][k][lft-1]+p[i].c;
					
					f[i][j][k][lft]=max(x,max(y,z));
					ans=max(ans,f[i][j][k][lft]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
