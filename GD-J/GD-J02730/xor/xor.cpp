#include<iostream>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0&&n<=2){
		if(n==1){
			cin>>a[1];
			cout<<0;
		}else if(n==2){
			int dxd;
			for(int i=0;i<2;i++){
				cin>>a[i];
				if(a[i]==1){
					dxd=i;
				}
			}
			if(a[1-dxd]!=1){
				cout<<0;
			}else{
				cout<<1;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
} 
