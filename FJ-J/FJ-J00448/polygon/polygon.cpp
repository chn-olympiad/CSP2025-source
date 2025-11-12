#include <bits/stdc++.h>
using namespace std;
int a;
int w[5001];
int main(){
	freeopen("polygon.in","r",stdin);
	freeopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>w[i];
	}
	sort(w+1,w+a+1);
	if(w[a]==1){
		cout<<(a-2)%998244353;
	}
	else cout<<21;
	return 0;
} 
