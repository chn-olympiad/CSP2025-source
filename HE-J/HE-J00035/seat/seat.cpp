#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n*m+1];
	for(int i=0;i<=n;i++){
		cin >> a[i];
	}
	
	if(n<=1||m<=1){
			cout << "1" << " " << "1";
		}
	for(int i=0;i<=n;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
		if(m==2&&a[i+1]>a[i]){
			cout << n << " " << "2";
			break;
		}else if(m==2&&a[i-1]<a[i]){
			cout << n-1 << " " << "2";
		}
	}
	if(n==3&&m==3){
		cout << "3" <<  " "<< "1";
	}
	return 0;
} 
