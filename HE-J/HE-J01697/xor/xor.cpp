#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	int a[500005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+k+1);
	cout<<a[1];
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
} 
