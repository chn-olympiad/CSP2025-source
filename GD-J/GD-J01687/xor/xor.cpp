#include <iostream>
using namespace std;
int n;
int k;
int a[50009];
int totnum=0;

int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==k){
			totnum++;
		}
	}
	cout<<totnum;
	return 0;
} 
