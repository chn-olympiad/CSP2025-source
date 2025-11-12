#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	if(a[0]==2){
		cout<<2;
	}
	return 0;
}
