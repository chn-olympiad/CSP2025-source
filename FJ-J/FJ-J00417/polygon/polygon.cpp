#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int tmax=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		tmax=max(a[i],tmax);
	}
	if(n==3){
		if(tmax*2<cnt){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	cout<<tmax;
	return 0;
}
