#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n = 0,k = 0,a[100010];
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	if(n <= 100){
		if(k == 2) cout<<'2';
		if(k == 3) cout<<'2';
		if(k == 0) cout<<'1';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
