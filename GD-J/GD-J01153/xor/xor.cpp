#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000100],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]==k)s++;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
