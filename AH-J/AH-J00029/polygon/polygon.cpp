#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,Max=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		Max=max(Max,a[i]);
	}
	if(sum>2*Max)ans++;
	cout<<ans%MOD;
	return 0;
}
//R
