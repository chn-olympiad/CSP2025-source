#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[1000002];

int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k=0) cout<<0;
	if(k=1) cout<<n;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
