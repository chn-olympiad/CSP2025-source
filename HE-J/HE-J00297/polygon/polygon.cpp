#include<bits/stdc++.h>
using namespace std;
const int m=998244353;
int a[5010],d[114514];
int ans,z;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(z<a[i]){
			z=a[i];
		}
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*z){
			cout<<1;
		}
	}
	else{
		cout<<2*n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
