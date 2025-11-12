#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int INF=5100,Mod=998244353;
int a[INF],book[50010],tot,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
//	for (int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	book[0]=1;
	for (int i=1;i<=n;i++){
		tot+=a[i];
		int del=tot-2*a[i]-1;
		if (i>=3&&del>=0)for (int j=0;j<=del;j++)ans=(ans+book[j])%Mod;
		for (int j=tot-a[i];j>=0;j--){
			book[j+a[i]]=(book[j+a[i]]+book[j])%Mod;
		}
//		for (int j=0;j<=15;j++)cout<<book[j]<<" ";
//		cout<<endl;
//		cout<<tot<<" "<<del<<" "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
