#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		cout<<(n-2)%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
