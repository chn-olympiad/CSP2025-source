#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","t",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	int x,y;
	int cnt;
	cin>>n>>m;
	int b[n][m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			if(i>n){
				if(i%n==0){
					y=i/n;
				}
				else {
					y=i/n+1;
				}
					if(y%2==1){
						x=i%n;
					}
				else {
					if(i%n==0){
						x=i%n+1;
					}
					else {
						x=n-i%n+1;
					}
				}
			}
			else {
				y=1;
				x=i;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
