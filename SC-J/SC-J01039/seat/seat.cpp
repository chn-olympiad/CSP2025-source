#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[15][15];
int a[105];
int t,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)t=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int X=1,Y=1;
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			if(a[cnt]==t){
				cout<<Y<<' '<<X;
				exit (0);
			}
			if(Y%2==1){
				X++;
				if(X>n){
					X=n;
					Y++;
				}
			}
			else{
				X--;
				if(X==0){
					X=1;
					Y++;
				}
			}
			
		}
		
	}
	return 0;
}