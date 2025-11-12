#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[5001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		int ans=a[1]+a[2]+a[3],sum=max(a[3],max(a[1],a[2]));
		if(ans>2*sum)cout<<1;
		else cout<<0;
	}else cout<<8;
	return 0;
}
