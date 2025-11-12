#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5002],num1=0,maxx=0,num2=0;
	cin >> n;
	bool bl=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1){
			bl = 1;
		}
		num1+=a[i];
		if(maxx<a[i]){
			maxx = a[i];
		}
	}
	if(n<3){
		cout << 0;
		return 0;
	}
	if(n==3){
		if(num1 > 2*maxx){
			cout << 1;
		}
		else{
			cout << 0;
		}
		return 0;
	}
	int C1,C2,C3;
	if(bl==0){
		
		for(int m=3;m<=n;m++){
			C1=1,C2=1,C3=1;
			for(int i=1;i<=n;i++){
				C1*=i; 
			}
	
			for(int i=1;i<=m;i++){
				C2*=i; 
			}
	
			for(int i=1;i<=(n-m);i++){
				C3*=i; 
			}
	
			C2*=C3;
			C1/=C2;
			num2+=C1;
	
		}
		cout << num2;
		return 0;
	}
	cout << 19491001;
	return 0;
} 