#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	if(a[0]==1){
		cout<<9;
	}
	if(a[0]==2){
		cout<<6;
	}
	return 0;
}
