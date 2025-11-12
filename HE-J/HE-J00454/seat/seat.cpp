#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[150];
int op;
int k;
int r[1010][1010];
void solve(int y){
	while(k!=0){
		if(y%2==1){
			for(int i=1;i<=n;i++){
				r[i][y]=a[k];
				k--;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				r[i][y]=a[k];
				k--;
			}
		}
		y++;
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	op=a[1];
	sort(a+1,a+1+k);
	solve(1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r[i][j]==op){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	
	
	return 0;
}
