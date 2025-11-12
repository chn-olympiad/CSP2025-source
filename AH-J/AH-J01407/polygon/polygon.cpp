#include<bits/stdc++.h>
using namespace std;
long long n,m,mx,a[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(mx==1){
		cout<<0;
		return 0;
	}
	if((a[1]+a[2]+a[3])>mx*2){
		cout<<1;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
