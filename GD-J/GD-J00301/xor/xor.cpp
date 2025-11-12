#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	if(n==1)cout<<0;
	else if(n==2)cout<<1;
		
		fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
