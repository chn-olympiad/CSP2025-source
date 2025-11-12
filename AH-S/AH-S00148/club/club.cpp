#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
struct stu{
	int u,v,w;
}tp[N];
int n,a[N][4];
int f[2][102][102][102];
bool check1(){
	for(int i=1;i<=n;i++){
		for(int j=2;j<=3;j++){
			if(a[i][j]){
				return false;
			}
		}
	}
	return true;
}
bool cmp1(stu x,stu y){return x.u>y.u;}
void solve1(){
	sort(tp+1,tp+n+1,cmp1);
	int sum=0;
	for(int i=1;i<=n/2;i++){
		sum+=tp[i].u;
	}
	cout<<sum<<endl;
	return;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i][3]){
			return false;
		}
	}
	return true;
}
int F[N][4],G[N][4];
void solve2(){
	// sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			for(int k=1;k<=2;k++){
				int peo[3]={0};
				peo[k]=G[i-1][k],peo[3-k]=(i-1)-G[i-1][k];
				if(F[i][j]<F[i-1][k]+a[i][j]&&peo[j]+1<=n/2){
					G[i][j]=peo[j]+1;
					F[i][j]=F[i-1][k]+a[i][j];
				}
			}
		}
	}
	cout<<max(F[n][1],F[n][2])<<endl;
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					f[0][i][j][k]=f[1][i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			tp[i]=(stu){a[i][1],a[i][2],a[i][3]};
		}
		if(check1()){
			solve1();
			continue;
		}
		if(n<=200){
			int p=0;
			for(int i=1;i<=n;i++){
				p^=1;
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=min(i,n/2);k++){
						for(int l=i-j-k;l>=0&&l<=min(i,n/2);l++){
							f[p][j][k][l]=max(f[p][j][k][l],
									      max((j?(f[p^1][j-1][k][l]+a[i][1]):0),
										  max((k?(f[p^1][j][k-1][l]+a[i][2]):0),
											  (l?(f[p^1][j][k][l-1]+a[i][3]):0))));
						}
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=n-i-j;k>=0&&k<=n/2;k++){
						ans=max(ans,f[p][i][j][k]);
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(check2()){
			solve2();
			continue;
		}
	}
	return 0;
}