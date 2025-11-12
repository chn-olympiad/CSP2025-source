#include <bits/stdc++.h>
using namespace std;
long long a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,sum=0,mx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(a[i],mx);
	}
	if(sum>mx*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
