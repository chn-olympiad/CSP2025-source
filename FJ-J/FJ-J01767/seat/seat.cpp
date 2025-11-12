#include <bits/stdc++.h>
using namespace std;
struct S{
	int cj,x,y;
	bool flag=0;
}a[1001];
bool cmp(S x,S y){
	return x.cj>y.cj;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].cj;
	a[1].flag=1;
	sort(a+1,a+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[cnt].x=i;
			cnt++;
		}
	}
	cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[cnt].y=j;
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[cnt].y=j;
				cnt++;
			}
		}
	}
	for(int i=1;i<=n*m;i++) if(a[i].flag) cout<<a[i].x<<" "<<a[i].y;
	return 0;
}

