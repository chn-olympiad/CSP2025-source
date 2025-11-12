#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[100001][3];
struct Node{
	int num,c1,c2,c3;
}f[100001][3];
void solve(){
	for(int i=1;i<=n;i++){
		f[i][0].num=-1,f[i][1].num=-1,f[i][2].num=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(f[i-1][j].c1+1<=n/2){
				if(f[i-1][j].num+a[i][0]>f[i][0].num){
					f[i][0].num=f[i-1][j].num+a[i][0];
					f[i][0].c1=f[i-1][j].c1+1;
					f[i][0].c2=f[i-1][j].c2;
					f[i][0].c3=f[i-1][j].c3;
				}
			}
			if(f[i-1][j].c2+1<=n/2){
				if(f[i-1][j].num+a[i][1]>f[i][1].num){
					f[i][1].num=f[i-1][j].num+a[i][1];
					f[i][1].c1=f[i-1][j].c1;
					f[i][1].c2=f[i-1][j].c2+1;
					f[i][1].c3=f[i-1][j].c3;
				}
			}
			if(f[i-1][j].c3+1<=n/2){
				if(f[i-1][j].num+a[i][2]>f[i][2].num){
					f[i][2].num=f[i-1][j].num+a[i][2];
					f[i][2].c1=f[i-1][j].c1;
					f[i][2].c2=f[i-1][j].c2;
					f[i][2].c3=f[i-1][j].c3+1;
				}
			}
		}
	}
	int ans=0;
	ans=max(f[n][0].num,max(f[n][1].num,f[n][2].num));
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		solve();
	}
	return 0;
} 
/*                            */
