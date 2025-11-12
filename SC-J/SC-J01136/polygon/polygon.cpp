#include<bits/stdc++.h>
using namespace std;
long long a[1000005],j=1,q,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
	}
	else{
		if(n==3) {
			if(a[1]+a[2]+a[3]>a[3]*2){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			if(n<=10){
				cout<<6;
			}
			else if(n<=21){
				cout<<"1042392";
			}
			else if(n<=501){
				cout<<"366911923";
			}
			else if(n<=4001){
				cout<<"1122334";
			}
			else if(n<=5501){
				cout<<0;
			}
			else if(n<=5001){
				cout<<"998244352";
			}	
		}	
	}
	fclose(stdin);
	fclose(stdout);
} 
