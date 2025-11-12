//GZ-S00046 刘啸行 贵阳市新世界学校
#include<bits/stdc++.h>
using namespace std;
struct A{
	int i,j,w;
}a[300005];
bool cmp(A x,A y){
	return x.w > y.w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for(int i = 1;i<=n;i++){
			cin >> a[i*3-2].w >> a[i*3-1].w >> a[i*3].w;
			a[i*3-2].i = i;
			a[i*3-1].i = i;
			a[i*3].i = i;
			a[i*3-2].j = 1;
			a[i*3-1].j = 2;
			a[i*3].j = 3;
		}
		//for(int i = 1;i<=3*n;i++){cout << a[i].i << ' ' << a[i].j << ' ' << a[i].w << '\n'; }
		sort(a+1,a+1+3*n,cmp);
		int cnt[4]={0},flag[4]={0},lim=n/2,ans=0;
		bool vis[100005]={0};
		for(int i = 1;i<=3*n;i++){
			int I = a[i].i,J = a[i].j,W = a[i].w;
			if(vis[I])continue;
			cnt[J]++;
			if(J==1&&flag[1]==0){
				if(cnt[1]>lim)flag[1]=1;
				else{
					vis[I]=1;
					ans+=W;
				}
			}else if(J==2&&flag[2]==0){
				if(cnt[2]>lim)flag[2]=1;
				else{
					vis[I]=1;
					ans+=W;
				}
			}else if(J==3&&flag[3]==0){
				if(cnt[3]>lim)flag[3]=1;
				else{
					vis[I]=1;
					ans+=W;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
