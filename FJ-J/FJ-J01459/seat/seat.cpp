#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r,x=1,y=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==r){
			cout<<x<<" "<<y;
			return 0;
		}
		if (x%2==1){
			if (y==n){
				x++;
			}
			else {
				y++;
			}
		}
		else {
			if (y==1){
				x++;
			}
			else {
				y--;
			}
		}
	}
	return 0;
} 
