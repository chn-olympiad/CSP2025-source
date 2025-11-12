#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],k,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			k = n*m-i+1;
			break;
		}
	}
	y = (k-1)/n+1;
	if(y%2==0)
		x = n-(k-1)%n;
	else
		x = (k-1)%n+1;
	cout << y << " " << x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
