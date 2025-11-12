#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&(a[1]+a[2]>a[3]||a[1]+a[3]>a[2]||a[3]+a[2]>a[1])){
		ans++;
		cout<<ans;
		return 0;
	}
	return 0;
}
