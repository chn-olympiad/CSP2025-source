#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {cin>>a[i];}
	int gar=a[1];
	sort(a+1,a+(n*m)+1);
	int b[105];
	for(int i=n*m-1;i>=0;i--){
		b[i+1]=a[n*m-i];
	}
	int x_now=1,y_now=1,x_add=1,cnt=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(gar==b[cnt++]){
				cout<<y_now<<" "<<x_now;
			 	return 0;
			}
			x_now+=x_add;
		}
		y_now++;
		x_add=-(x_add);
		x_now+=x_add;
	}
	return 0;
}