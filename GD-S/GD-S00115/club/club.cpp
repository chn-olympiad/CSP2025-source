#include<algorithm> 
#include<iostream> 
#include<cstdio> 
#include<math.h> 
#include<string> 
#include<map> 
using namespace std;
const int N=1e5+10,M=1e3+10;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
int n,m,k,T,f[M][M],ff[200][200][200];
struct node{
	int x,y,z;
}a[N];
bool cmpx(node a,node b){
	return a.x>b.x;
}
bool cmpy(node a,node b){
	return a.y>b.y;
}
bool cmpz(node a,node b){
	return a.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		long long ans=0;
		a[0].y=a[0].z=0;
		for(int i=1;i<=n;i++){
			//cin>>a[i].x>>a[i].y>>a[i].z;
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[0].y=max(a[0].y,a[i].y);
			a[0].z=max(a[0].z,a[i].z);
		}
		if(a[0].y==0){
			sort(a+1,a+n+1,cmpx);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(a[0].z==0){
			//cout<<"A";
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					f[i][j]=0;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=n/2;i>=0;i--){
					for(int j=n/2;j>=0;j--){
						if(i>0)f[i][j]=max(f[i][j],f[i-1][j]+a[k].x);
						if(j>0)f[i][j]=max(f[i][j],f[i][j-1]+a[k].y);
						ans=max(ans,1ll*f[i][j]);
					}
				}
			}
			cout<<f[n/2][n/2]<<'\n';
			continue;
		}
		if(n<=30){
		for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
				for(int l=0;l<=n/2;l++){
					ff[i][j][l]=0;
				}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=n/2;i>=0;i--){
					for(int j=n/2;j>=0;j--){
					for(int l=n/2;l>=0;l--){
						//cout<<i<<' '<<j<<' '<<l<<'\n';
						if(i>0)ff[i][j][l]=max(ff[i][j][l],ff[i-1][j][l]+a[k].x);
						if(j>0)ff[i][j][l]=max(ff[i][j][l],ff[i][j-1][l]+a[k].y);
						if(l>0)ff[i][j][l]=max(ff[i][j][l],ff[i][j][l-1]+a[k].z);
						ans=max(ans,1ll*ff[i][j][l]);
					}
					}
				}//cout<<'\n';
			}//cout<<'\n';
			//cout<<ff[0][1][0]<<' ';
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int t=max(a[i].x,a[i].y);
			t=max(t,a[i].z);
			ans+=t;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
