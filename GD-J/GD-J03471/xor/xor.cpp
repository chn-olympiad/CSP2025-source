#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	vector<int> num(n+1),v(n+1);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	if(k=0) cout<<0;
	else if(k=1) cout<<n;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
