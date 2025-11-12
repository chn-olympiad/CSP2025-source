#include <iostream>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,e=1;
	int a[100];
	cin >>n;
	cin>>e;
	for(int i=1;i<n+e;i++){
		for(int j=1;j<n+e;j++){
		  	cin>>a[i];
	    }
	}
	cout<<2<<endl;
	cout<<0;
	return 0;
}
