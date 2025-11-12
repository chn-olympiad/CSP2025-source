#include<iostream
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0; 
	for(int i=0;i<n;i++){
		cin>>i;
		sum+=i;
	}
	for(int i=0;i<n;i++){
		if(n==3){
			if(max(i+1,i)*2<sum&&m>=3){
				cout<<1;
			}
		}
		
	}
	return 0;
}
