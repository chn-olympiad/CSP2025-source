#include <bits/stdc++.h>
using namespace std;

struct e{
	int a,b,c;
};

long long n,t,a[201][4],f[101][101][101],ans;
bool cmp(e c,e d){
	return c.a>d.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int h=1;h<=t;h++){
		cin>>n;
		if (n<=200){
			for (int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			for (int j=0;j<=n/2;j++){
				for (int k=0;k<=n/2;k++){
					for (int l=0;l<=min(n-j-k,n/2);l++){
						if (j>0) f[j][k][l]=max(f[j][k][l],f[j-1][k][l]+a[j+k+l][1]);
						if (k>0) f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+a[j+k+l][2]);
						if (l>0) f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+a[j+k+l][3]);
						if (j+k+l==n) ans=max(ans,f[j][k][l]);
					}
				}
			}
			cout<<ans;
		}
		else{
			e b[n+1];
			for (int i=1;i<=n;i++){
				cin>>b[i].a>>b[i].b>>b[i].c;
			}
			if (b[1].c==0&&b[1].b==0){
				sort(b+1,b+1+3*n,cmp);
				for (int i=1;i<=n/2;i++){
					ans+=b[i].a;
				}
			cout<<ans;
			}
		}
	}
	return 0;
}
