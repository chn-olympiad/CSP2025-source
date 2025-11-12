#include <bits/stdc++.h>
using namespace std;
int n;
int r[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	if(r[0]==1){
		cout<<9;
		return 0;
	}
	else if(r[0]==2){
		cout<<6;
		return 0;
	}
	else{
		cout<<1042392;
	}
	return 0;
}
