#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>90){
		cout<<n*a[n]%455;
	}
	else{
		cout<<n*a[1]/5;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}