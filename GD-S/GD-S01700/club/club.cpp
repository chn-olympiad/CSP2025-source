#include<bits/stdc++.h>
using namespace std;

int t,x,y,z,mmax,mmin,mmid,ans,a[10005][5],x1[1000],y1[1000],z1[1000],fr[100005],n,zhan1,zhan2;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int d,int n){
	if(d==n+1){
		ans = 0;
		for (int i = 1;i <= x;i++){
			ans+=x1[i]; 
		}
		for (int i = 1;i <= y;i++){
			ans+=y1[i]; 
		}
		for (int i = 1;i <= z;i++){
			ans+=z1[i]; 
		}
		mmax = max(mmax,ans);
		return;
	}
	if(x<n/2){
		x++;x1[x]=a[d][1];
		dfs(d+1,n);
		x--;
	}
	if(y<n/2){
		y++;y1[y]=a[d][2];
		dfs(d+1,n);
		y--;
	}
	if(z<n/2){
		z++;z1[z]=a[d][3];
		dfs(d+1,n);
		z--;
	} 
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		mmax = 0;
		cin >> n;
		if(n>200){
			ans = 0;
			for (int i = 1;i <= n;i++){
				cin >> fr[i] >> zhan1 >> zhan2; 
			}
			sort(fr+1,fr+n+1,cmp);
			for (int i = 1;i <= n/2;i++){
				ans+= fr[i];
			}
			cout << ans << endl;
			continue;
		}
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= 3;j++){
				cin >> a[i][j];
			}
		}
		dfs(1,n);
		cout << mmax << endl;
	}
	return 0;
}
/* 
2
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
