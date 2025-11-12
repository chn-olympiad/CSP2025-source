#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int m,n,a[103],sum_,big=0,Rm=1,Rn=1,k=1;
	cin >> m >> n;
	sum_=n*m;
	
	for(int i = 1;i <= sum_;i++){
		cin >> a[i];
	}
	
	for(int i = 2;i<=sum_;i++){

		
		if (a[i]>a[1]){
			cout << Rm << " " << Rn << endl; 
			if(Rm%2==0){
				k=-1;
				if(Rn==1){
					Rm+=1;
					Rn+=k;
					k=1;
				}
			}
			else{
				k=1;
				if(Rn==n){
					Rm+=1;
					Rn+=k;
					k=-1;
				}
			}
			Rn+=k;
		}
		 
	}
	cout << Rm << " " << Rn; 
	return 0;
} 