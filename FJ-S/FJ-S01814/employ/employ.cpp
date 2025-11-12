#include <iostream>
#include <string>
using namespace std;

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int n;
	int m;
	int v=1;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[1000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v=v*a[i];
	}
	cout<<v*(n/m);
	return 0;
}
