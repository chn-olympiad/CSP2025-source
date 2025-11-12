#include <bits/stdc++.h>
using namespace std;
long long n,a[500000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	if(n<=2||n==3&&(a[0]+a[1]+a[2])<=a[2]*2){
		cout<<0;
	}else cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}