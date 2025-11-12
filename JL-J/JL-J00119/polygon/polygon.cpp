#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010],s[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==1||n==2){
		cout<<0;
	}else if(a[1]+a[2]>a[3]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
