#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=3e4+5;
int t,n;
long long a[N][4],ans,ff,f[N/2][N/2];
long long maxx(long long i,long long j){
	return i>j?i:j;
}
long long minn(long long i,long long j){
	return i<j?i:j;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i+=1){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int x=n/2;x>=0;x-=1){
				for(int y=minn(n/2,i-x);y>=0;y-=1){
					int z=i-x-y;
					if(z>n/2)continue;
					ff=0;
					if(x)ff=maxx(ff,f[x-1][y]+a[i][1]);
					if(y)ff=maxx(ff,f[x][y-1]+a[i][2]);
					if(z)ff=maxx(ff,f[x][y]+a[i][3]);
					f[x][y]=ff;
					ans=max(ans,f[x][y]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

