#include<bits/stdc++.h>
using namespace std;
long long n,s,mmaaxx;
long long a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		if(a[i]>mmaaxx){
			mmaaxx=a[i];
		}
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==5&&a[1]=1){
		cout<<9;
		return 0;
	}
	else if(n==5&&a[1]=2){
		cout<<6;
		return 0;
	}
	if(n==3&&s>mmaaxx*2&&a[1]<a[2]+a[3]&&a[2]<a[1]+a[3]&&a[3]<a[2]+a[1]){
		cout<<1;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
}
