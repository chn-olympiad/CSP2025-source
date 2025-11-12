#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],be[5005],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) be[i]=be[i-1]+a[i];
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++)
		if((be[j]-be[i]+a[i])>2*a[j]) cnt++;
	}
	cout<<cnt;
	return 0;
}
