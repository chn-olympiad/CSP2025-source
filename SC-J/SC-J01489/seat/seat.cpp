#include<bits/stdc++.h>
#define ll long long
#define Suika 0
using namespace std;
const int N=20;
int n,m,a[N][N];
int b[N*N];
int cnt,res,ansx,ansy;
bool cmp(int a,int b) {
	return a>b;
} 
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
			b[++cnt]=a[i][j];
		}
	}
	res=b[1];
	sort(b+1,b+cnt+1,cmp);
	int tot=1;
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) a[j][i]=b[tot++];
		} else {
			for(int j=n; j>=1; j--) a[j][i]=b[tot++];
		}
		for(int j=1; j<=n; j++) if(a[j][i]==res) {
			ansx=j;
			ansy=i;
			break;
		}
	}
	cout<<ansy<<" "<<ansx;
	return Suika;
}