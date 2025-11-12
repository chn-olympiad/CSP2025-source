#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n, wood[5005];
	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>wood[i];
	}
	
	if(n<3){
		cout<<0;
		return 0;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
