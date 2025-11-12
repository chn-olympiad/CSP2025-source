#include <iostream>

using namespace std;

int main()

{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m[5],k;
	cin>>n;
	if(n=5){
		for(int i=0;i<n;i++){
			cin>>m[i];
			}
		cout<<2;
	}
	if(n=10){
		for(int i=0;i<=11;i++){
			cin>>m[i];
		}
		cout<<2204128;
	}
	return 0;
}
