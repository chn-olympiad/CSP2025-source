#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int main(){
	freopen("F:\number\seat.in","w",stdin);
	freopen("F:\number\seat.out","s",stdout);
	int n,m,s[1145],c=0,x=1,y=1,e[11][11];
	cin >> n >> m;
	for (int i=0;i<n*m;i++) cin >> s[i];
	for (int i=1;i<n*m;i++) if (s[i]>s[0]) c++;
	int f=s[0];
	sort(s+0,s+n*m,cmp);
	for (int i=0;i<n*m;i++) {
		e[x][y]=s[i];
		if (x%2) {
			if (y!=n) y++;
			else x++;
		} else if (y!=1) y--;
		else x++;
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (e[i][j]==f) {
		cout << i << ' ' << j;
		break;
	}
}