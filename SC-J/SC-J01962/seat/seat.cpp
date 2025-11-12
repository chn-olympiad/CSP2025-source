#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=110;

int n,m;
int ra,a[N];
int ans[20][20];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ra=a[1];
	sort(a+1,a+1+n*m,cmp);
	int c=0;
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++) ans[i][j]=a[++c];
		}
		else for(int i=n;i>=1;i--) ans[i][j]=a[++c];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==ra){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}


