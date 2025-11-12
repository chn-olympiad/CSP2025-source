#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,x,a[102],s[12][12],cnt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[++cnt];
	x=a[1];
	sort(a+1,a+1+cnt);
	for(int i=1;i<=m;i++){
		if(i%2) for(int j=1;j<=n;j++) s[j][i]=a[cnt--];
		else for(int j=n;j>=1;j--) s[j][i]=a[cnt--];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==x){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}