#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int nuu[n];
	for(int i=0;i<n;i++){
		cin>>nuu[i];
	}
	if(nuu[0]+nuu[1]>nuu[2]&&nuu[1]+nuu[2]>nuu[0]&&nuu[0]+nuu[2]>nuu[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
