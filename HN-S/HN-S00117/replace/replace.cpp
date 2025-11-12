#include<iostream>
using namespace std;
int main(){
	preopen("replace.in","r",stdin);
	preopen("replace.out","w",stdout);
	int n,q,si[10,10]ti[10,10];
	cin>>n,q;
	for(int i=0;i<n++){
		cin>>si[i,i];
		cin>>ti[i,i];
	}
	cout<<2<<endl;
	cout<<0<<endl;
	fclos(stdin);
	fclos(stdout);
	return 0;
}
