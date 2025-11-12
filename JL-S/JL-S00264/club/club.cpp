#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
	int a,b,c;
	// double x,y,z;
	// void init(){
	// 	int t=min({a,b,c});
	// 	if (t==0) x=1e9*a,y=1e9*b,z=1e9*c;
	// 	else x=1.*a/t,y=1.*b/t,z=1.*c/t;
	// }
};

// inline int min2(int a,int b,int c){
// 	return a+b+c-min({a,b,c})-max({a,b,c});
// }

inline bool cmp(Node u,Node v){
	return max({u.a,u.b,u.c})>max({v.a,v.b,v.c});
}

int n;
Node a[100001];
ll f[201][201][201];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		int lim=n/2;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=lim;j++){
				for (int k=0;k<=lim;k++) f[i][j][k]=-1e18;
			}
		}
		f[0][0][0]=0;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=lim;j++){
				for (int k=0;k<=lim;k++){
					if (j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].a);
					if (k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].b);
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].c);
				}
			}
		}
		ll maxn=0;
		for (int i=0;i<=lim;i++){
			for (int j=0;j<=lim;j++){
				if (n-i-j<=lim) maxn=max(maxn,f[n][i][j]);
			}
		}
		cout<<maxn<<"\n";
	}
	return 0;
}
/*

*/