#include <bits/stdc++.h>
using namespace std;

#define int long long

struct People{
	int x,y,z;
	bool operator < (const People &A) const{
		return x>A.x;
	}
}a[100011];

int f[211][111][111],t,n,ans;

inline void solve1(){
	memset(f,128,sizeof(f));
	f[0][0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n/2;j++)
			for(int k=0;k<=n/2;k++){
				f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[i+1].x);
				f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[i+1].y);
				if(i-j-k+1<=n/2)
					f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+1].z);
			}
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			ans=max(ans,f[n][i][j]);
	printf("%lld\n",ans);
	return;
}
inline void solve2(){
    sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)
		ans+=a[i].x;
	for(int i=n/2+1;i<=n;i++)
		ans+=max(a[i].y,a[i].z);
	printf("%lld\n",ans);
	return;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    for(;t--;){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
        ans=0;
        if(n<=200)
			solve1();
		else
			solve2();
    }
    return 0;
}
