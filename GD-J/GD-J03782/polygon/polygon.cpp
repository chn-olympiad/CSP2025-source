#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mx,ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(sum>2*mx){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
