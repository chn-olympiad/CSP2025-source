#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ps[50005],anse,mx,ans[233];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];	
	sort(a+1,a+1+n);
	if (n==3 and a[1]+a[2]>a[3]){
		cout<<1;
		return 0;
	}
	return 0;
}
