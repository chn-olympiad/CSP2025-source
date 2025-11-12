#include <iostream>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n = 0;
	int m = 0;
	cin>>n>>m;
	int a[105] = {};
	int z = n*m;
	for(int i = 0;i<z;i++){
		cin>>a[z];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int q = j;
			q++;
			if(a[j]<a[q]){
				int t = a[j];
				a[j] = a[q];
				a[q] = t;
			}
		}
	}
	cout<<a;
	return 0;
}
