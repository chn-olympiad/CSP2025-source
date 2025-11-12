#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3]&&a[3]-a[2]<a[1]&&a[3]-a[1]<a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	return 0;
}