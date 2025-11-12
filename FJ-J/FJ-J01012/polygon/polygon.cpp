#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[5010];
int check10(int n){
	int maxa=max(a[1],max(a[2],a[3]));
	int mmm=a[1]+a[2]+a[3];
	if(mmm-maxa>maxa){
		return true;
	}
	return false;
	
} 
int check20(int n){
	int o=(n-2)*n%998244353;
	int ans=(n+1)*(n-2)/2%998244353;
	return (o-ans)%998244353;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	if(n==3){
		cout<<check10(n)<<endl;
	}else if(maxa==1){
		cout<<check20(n)<<endl;
	}
	return 0;
}
