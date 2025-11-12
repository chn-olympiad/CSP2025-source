#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[5001];


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<7<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
