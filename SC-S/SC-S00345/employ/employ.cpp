#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[502];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m>=998244353){
		cout<<0;
		return 0;
	}
	int summ=1,sumn=1,sum=1;
	for(int i=2;i<=n;i++) sumn*=i,sumn%=998244353;
	for(int i=2;i<=m;i++) summ*=i,summ%=998244353;
	for(int i=2;i<=n-m;i++) sum*=i,sum%=998244353;
	cout<<sumn/((summ*sum)%998244353);
	return 0;
}