#include <bits/stdc++.h>
using namespace std;
int n,m,a[4000],sn,sm;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int fl=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int h=(i-1)*n+j;
			if(a[h]==fl){
				sm=i;
				if(i%2==1) sn=j;
				else sn=n-j+1;
				break;
			}
		}
	}
	cout<<sm<<' '<<sn;
	return 0;
}