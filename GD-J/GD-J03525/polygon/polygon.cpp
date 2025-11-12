#include<bits/stdc++.h>
using namespace std;
int n,a[10000],num,ans;
int main(){
	freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(num=a[n]*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
