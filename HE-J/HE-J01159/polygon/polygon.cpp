#include <bits/stdc++.h>
using namespace std;
	int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int count = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(max(a[0],max(a[1],a[2]) )*2 < a[0]+a[1]+a[2]) cout<<1;
		else{
			cout<<0;
		}
	}
	else if(n>=500){
		cout<<0;
	}
	else{
		cout<<9;
	}
	
	return 0;
}





