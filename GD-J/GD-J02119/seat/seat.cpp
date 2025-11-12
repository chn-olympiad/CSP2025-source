#include <bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,k,p,a[111];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) cin >> a[i];
	p=a[1];
	sort(a+1,a+n*m+1);
	k=n*m;
	while (k){
		if (y==1){
			for ( ;y<=n;y++){
				if (a[k]==p){
					cout << x << " " << y;
					return 0;
				}
				k--;
			}
			y--;
		}else{
			for ( ;y>=1;y--){ 
				if (a[k]==p){
					cout << x << " " << y;
					return 0;
				}
				k--;
			}
			y++;
		}
		x++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
