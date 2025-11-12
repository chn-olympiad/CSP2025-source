#include<bits/stdc++.h>
using namespace std;
int n,a[5100],mn,mx=1e9;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
	}else{
		if((a[1]+a[2]>a[3])&&(a[2]+a[3]>a[1])&&(a[1]+a[3]>a[2])){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}