#include<bits/stdc++.h>
using namespace std;

int n,m;
long long R;
long long a[200];

int cmp(int a,int b){
	if (a>b){
		return true;
	}
	return false;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m ;
	for (int i=1;i<=n*m;i++){
		cin >> a[i] ;
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int bj=0;
	for (int i=1;i<=n*m;i++){
		if (R==a[i]){
			bj=i;
			break;
		}
	}
	//cout << bj << endl ;
//	for (int i=1;i<=n*m;i++){
//		cout << a[i] ;
//	}
	long long hang=0,lie=0;
	if (bj%n==0){
		//cout << int(bj/n)*1.0 << " " << bj/n*1.0 << endl ;
		lie=bj/n;
	}else{
		lie=int(bj/n)+1;
	}
	hang=bj%n;
	if (lie%2==0){
		if (hang==0){
			hang=1;
		}else{
			hang=n-hang+1;
		}
	
	}else{
		if (hang==0){
			hang=n;
		}
	}
	cout << lie << " " << hang ;
	
	return 0;
}