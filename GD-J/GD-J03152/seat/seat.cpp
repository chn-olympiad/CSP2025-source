#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int n,m,cnt;
struct ly{
	int id,val;
} c[110];
bool cmp(ly x,ly y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i].val;
		c[i].id=i;
	}
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=c[++cnt].id;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[i][j]=c[++cnt].id;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
