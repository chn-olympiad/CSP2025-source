#include<bits/stdc++.h>
using namespace std;
struct ai{int x,y,z,sum;}a[100005];
bool cmp(ai x,ai y){return x.sum>y.sum;}
int t,n,f[100005][5],jy[100005][5][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z,a[i].sum=a[i].x+a[i].y+a[i].z;
		memset(f,0,sizeof(f));memset(jy,0,sizeof(jy));
		sort(a+1,a+n+1,cmp);
		f[1][1]=a[1].x,f[1][2]=a[1].y,f[1][3]=a[1].z;jy[1][1][1]++;jy[1][2][2]++;jy[1][3][3]++;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				int jl;
				for(int k=1;k<=3;k++){
					if(jy[i-1][k][j]>=n/2)continue;
					int xx=(j==1?a[i].x:(j==2?a[i].y:a[i].z));
					if(f[i-1][k]+xx>f[i][j])jl=k,f[i][j]=f[i-1][k]+xx;
				}
				jy[i][j][1]=jy[i-1][jl][1],jy[i][j][2]=jy[i-1][jl][2],jy[i][j][3]=jy[i-1][jl][3],jy[i][j][j]++;
			}
		}
		cout<<max(f[n][1],max(f[n][2],f[n][3]))<<"\n";
	}
	return 0;
}