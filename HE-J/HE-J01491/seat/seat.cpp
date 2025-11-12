#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int n=x*y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cj=a[1];
	sort(a+1,a+n+1);
	int js=n+1;
	for(int j=1;j<=y;){
		for(int i=1;i<=x;i++){
			js--;
			b[j][i]=a[js];
			if(cj==a[js]){
				cout<<j<<' '<<i;
			}
		}
		j++;
		for(int i=x;i>=1;i--){
			js--;
			b[j][i]=a[js];
			if(cj==a[js]){
				cout<<j<<' '<<i;
			}
		}
		j++;
}
	return 0;
}
