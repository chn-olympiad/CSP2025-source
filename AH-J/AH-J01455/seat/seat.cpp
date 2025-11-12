#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int snm=n*m;
	for(int i=1;i<=snm;i++){
		cin>>a[i];
	}
	int xx=a[1],inm=1;
	sort(a+1,a+1+snm,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(a[inm++]==xx){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[inm++]==xx){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
