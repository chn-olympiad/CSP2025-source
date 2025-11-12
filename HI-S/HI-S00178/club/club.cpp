#include <iostream>;
#include <cstdio>; 
#include <algorithm>;
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long a[1000][1000]; 
	int b,c,d;
	int t,n;
	cin >>t;
	cin >>n;
	for (int i=1;i<=n;i++){
	
			cin >>a[i][1];
			cin >>a[i][2];
			cin >>a[i][3];
			
		}
	for (int j=1;j<=n-1;j++){
		if (j!=n){
			b+=a[j][j];
		}
		else{
			j=1;
		}
			

	}
	if (n/2!=1){
		b+=a[1][1];
	}
	cout <<b+3;
	return 0;
}
