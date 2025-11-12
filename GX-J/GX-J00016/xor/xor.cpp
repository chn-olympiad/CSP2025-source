#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,aa[100005];
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>aa[i];
	}
	if(b==0)cout<<"1";
	else{
		if(a/2>b)cout<<b;
		else cout<<a/2;
	}
	return 0;
}
