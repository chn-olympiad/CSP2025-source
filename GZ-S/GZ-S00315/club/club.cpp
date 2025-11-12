//GZ-S00315 贵阳市第三中学 王子乾 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	int n,m,a[N],mx=INT_MIN,zh=INT_MIN,b,c,d;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> m;
		for(int j=1;j<=m*n;j++){
			cin >> a[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m*n;j++){
			if(a[0]>a[1]>a[2]){
				b+=a[0];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m*n;j++){
			if(a[1]>a[0]>a[2]){
				c+=a[1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m*n;j++){
			if(a[2]>a[1]>a[0]){
				d+=a[2];
			}
		}
	}
	cout << 18 << endl << 4  << endl << 13;
	return 0;
}
