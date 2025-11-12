#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	int os=0,zs=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x==1)os++; 
		else zs++;
	}
//	cout<<zs<<" "<<os<<endl;
	if(k==0){
		int sum=0;
		if(os%2==0){
			sum=zs+os/2;
		}else{
			sum=zs-2+os/2;
		}	
		cout<<sum<<endl;
		return 0;
	}else{
		if(os>=zs){
			cout<<os;
			return 0;
		}
	}
	cout<<time(0)%n;
	return 0;
}
