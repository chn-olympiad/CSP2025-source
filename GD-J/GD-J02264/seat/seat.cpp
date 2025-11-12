#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int r=1,c=1;
struct st{
	int pts, ind;
}p[150];
bool cmp(st A, st B){
	return A.pts >= B.pts;
}
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> p[i].pts;
		p[i].ind=i;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(p[i].ind==1){
			int t=i%(2*n);
			int tt=i/(2*n);
			if(t==0){
				
				cout<<tt*2+2<<" "<<1;
			}
			if(t>=1&&t<=n){
				
				cout<<tt*2+1<<" "<<t;
			}
			if(t>=n+1&&t<2*n){
				
				cout<<tt*2+2<<" "<<2*n+1-t;
			}
			return 0;
		}
	}
	return 0;
}
