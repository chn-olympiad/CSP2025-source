#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5010];
int n;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
	}else if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
