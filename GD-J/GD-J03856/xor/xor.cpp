#include<iostream>
#include<fstream>
using namespace std;
int n,k,a[500001],S,t,allsum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];t=0;
		for(int j=i;j>=S;j--){
			t^=a[j];
			if(t==k){allsum++;S=i+1;}
		}
	}cout<<allsum;

    return 0;
}

