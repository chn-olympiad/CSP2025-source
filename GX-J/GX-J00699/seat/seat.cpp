#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int ra=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[++cnt]==ra){
				if(i%2)cout<<i<<" "<<j;
				else cout<<i<<" "<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}
