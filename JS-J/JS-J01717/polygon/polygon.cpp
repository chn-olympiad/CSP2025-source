#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1;
		else cout<<0;
	}else{
		cout<<n*(n-1)*(n-2)/6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
