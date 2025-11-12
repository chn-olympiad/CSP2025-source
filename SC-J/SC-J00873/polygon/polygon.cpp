#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=5e3+5,mod=998244353;
int n,a[MAX],ans=0;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<"1\n";
		else cout<<"0\n";
	}else{
		cout<<n/3<<'\n';
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}