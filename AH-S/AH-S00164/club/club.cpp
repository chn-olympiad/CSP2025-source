#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int f[105][105][105];
int n,ans=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			for(int x=0;x<=min(n/2,i);x++){
				for(int y=0;y<=min(n/2,i-x);y++){
					int z=i-x-y;
					if(z>n/2) continue;
					//~ cout<<"i="<<i<<" | "<<x<<" "<<y<<" "<<z;
					if(x) f[x][y][z]=max(f[x-1][y][z]+a[i],f[x][y][z]);
					if(y) f[x][y][z]=max(f[x][y-1][z]+b[i],f[x][y][z]);
					if(z) f[x][y][z]=max(f[x][y][z-1]+c[i],f[x][y][z]);
					//~ cout<<" | f[x][y][z]="<<f[x][y][z]<<endl;
				}
			}
		}
		for(int x=0;x<=min(n/2,n);x++){
			for(int y=0;y<=min(n/2,n-x);y++){
				int z=n-x-y;
				if(z<=n/2) ans=max(ans,f[x][y][z]);
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
/*
To CCF: 
 This is my first CSP-S travel.
 I think it is very hard.
 I get more than 260 points is CSP-J.
 But this t1, I perhaps only get less than 55 points.
 Please give me 3= .
							Best wishes
							AH-S00164 
*/
