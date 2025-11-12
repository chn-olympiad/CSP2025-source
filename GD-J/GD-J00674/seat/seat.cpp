#include<bits/stdc++.h>
using namespace std;
int n,m,ans_x=1,ans_y=1,mp[150][150],a[1100],xr,cnt;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>a[i];
	}
	xr=a[0];
	sort(a,a+n*m+1,cmp);
	int i=0;
	bool change=false;
	while(i<=n*m) {
		if(ans_y<n&&change==false||cnt%2==0) {
			mp[ans_y][ans_x]=a[i];
			i++;
			ans_y++;
		}
		if(ans_y<n&&change==true||cnt%2==1) {
			mp[ans_y][ans_x]=a[i];
			i++;
			ans_y--;
		}
		if(ans_y==n||ans_y==1) {
			mp[ans_y][ans_x]=a[i];
			ans_x++;
			i++;
			change=!change;
			cnt++;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(mp[i][j]==xr) {
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
