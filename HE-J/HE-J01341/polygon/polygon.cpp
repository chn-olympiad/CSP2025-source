#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	else if(n=3){
		cout<<1<<endl;
		return 0;
	}
	return 0;
}
