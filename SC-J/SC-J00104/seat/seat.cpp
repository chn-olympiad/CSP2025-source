#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105],s[11][11];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];
	sort(a,a+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[cnt]==R){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[cnt]==R){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}