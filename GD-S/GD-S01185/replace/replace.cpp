#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin)
//	freopen("club.out","w",stdout)
	long long t;
	cin>>t;
	for(int d=1;d<=t;d++){
		long long n,ans=0;
		cin>>n;
		long long a[4][n+1],x[n+1],y[n+1],z[n+1],x1=0,y1=0,z1=0;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
					long long s,b,c,f,g,h,m,k,l;
					for(int i1=1;i1<=n;i1++){
						for(int i2=i1+1;i2<=n;i2++){
						for(int i3=i2+1;i3<=n;i3++){
						s=a[1][i1]+a[2][i2]+a[3][i3];
						b=a[1][i1]+a[3][i2]+a[2][i3];
						c=a[2][i1]+a[1][i2]+a[3][i3];
						f=a[2][i1]+a[3][i2]+a[1][i3];
						g=a[3][i1]+a[1][i2]+a[2][i3];
						h=a[3][i1]+a[2][i2]+a[1][i3];
						m=max(s,b);
						k=max(c,f);
						l=max(g,h);
						m=max(m,k);
						k=max(m,l);
						ans=max(ans,k);
					}
					}
					}
				cout<<ans;
			}}
