#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a,a+n+1);
	if(a[n]*2>sum){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}
	return 0;
}