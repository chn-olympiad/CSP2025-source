#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[5005],mul=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else if(a[n]==a[1]){
		n-=2;
		while(n>0) mul=mul*n%998244353,n--;
		cout<<mul;
	}
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
