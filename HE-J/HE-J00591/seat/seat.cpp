#include<bits/stdc++.h>
using namespace std;
int a[105],z[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,b=0;
	cin >>n>>m;
	if(n==1&&m==1){
		cout << n<<" "<<m;
		return 0;
	}
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	a1=a[0];
	sort(a,a+n*m);
	for(int i=m;i>=1;i--){
		if(i%2==0){
				for(int j=1;j<=n;j++){
					z[i][j]=a[b];
					b++;
				}
		}else{
		for(int j=n;j>=1;j--){
				z[i][j]=a[b];
				b++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a1==z[i][j]){
				cout << i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
