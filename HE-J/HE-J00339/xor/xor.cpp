#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int a[1048666];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+n+1);
	
	cout<<s/k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
