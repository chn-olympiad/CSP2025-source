#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
int n,m;
int x,y;
int cnt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++){
		y++;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				x++;
				if(r==a[cnt]){
					cout<<y<<" "<<x;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(r==a[cnt]){
					cout<<y<<" "<<x;
					return 0;
				}
				x--;
			}
		}
	}
	return 0;
}