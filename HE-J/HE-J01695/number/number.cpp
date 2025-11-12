#include<iostream>
using namespace std;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	for(int i=0;i<a;i++){		
		for(int j=0;j<i;j++){
			cin>>a[i];
		}
	}
	return 0;
}
