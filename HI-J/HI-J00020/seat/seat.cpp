#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,x=1,y=1,um=0,num=2,nu=1;
	cin >> n >> m;
	long long a[n*m+1],b[n*m+1];
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	sort(a+2,a+1+n*m);
	b[1]=a[1];
	for (int i=n*m;i>=2;i--){
		b[num]=a[i];
		num++;
	}
	for (int i=1;i<=n*m;i++){
		if (b[i+1]>b[1]){
			if (y==m&&um==0){
				um=1;
				nu=0;
				x++;
			}
			else if (y==1&&um==1){
				um=0;
				nu=0;
				x++;
			}
			if (um==1&&nu==1){
				y--;
			}
			else if (um==0&&nu==1){
				y++;
			}
		}
		else {
			break;
		}
		nu=1;
	}
	cout << x << " " << y;
	return 0;
}
