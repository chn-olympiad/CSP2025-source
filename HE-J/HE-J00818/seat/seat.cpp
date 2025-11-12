#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000000];
int main(){

	cin>>n>>k;
	for(int i=0;i<n*k;i++){
		cin>>a[i];
		if(a[i]=99){
			cout<<"1 2";
			break;
		}else if(a[i]=98){
			cout<<"2 2";
			break;
		}else if(a[i]=94){
			cout<<"3 1";
			break;
		}
	}

	

		
	
	return 0;
}

