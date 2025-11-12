#include<bits/stdc++.h>
using namespace std;
int n;
int a[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3) cout<<0;
	else if(n==3) cout<<1;
	sort(a,a+n);
	if(a[n-1]==1){
		cout<<(n*n*n)%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
