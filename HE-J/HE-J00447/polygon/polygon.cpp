#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
void bi(int q){
	int ans=0;
	for(int i=1;i<q;i++){
		ans+=i*q;
		--q;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n=3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])
		cout<<1;
	}else if(n<3){
		cout<<0;
	}else{
		int ans=0;
	for(int i=1;i<n;i++){
		ans+=i*n;
		--n;
	}
	cout<<ans;
	}
	return 0;
}
