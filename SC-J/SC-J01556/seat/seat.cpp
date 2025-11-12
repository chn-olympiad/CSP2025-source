#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[15][15];
int b[190];
int tz=0;
int ry=1;
int zx=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	tz=b[1];
	sort(b+1,b+1+(n*m),cmp);
	while(1){
		for(int i=1;i<=n;i++){
			if(b[zx]==tz){
				cout<<ry<<" "<<i;
				return 0;
			}
			zx++;
		}
		ry++;
		for(int i=n;i>=1;i--){
			if(b[zx]==tz){
				cout<<ry<<" "<<i;
				return 0;
			}
			zx++;
		}
		ry++;
	}
	return 0;
}