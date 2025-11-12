#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int _mod=998244353;
string s;
int n,m,c[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool flag=0;
	int sum=0;
	for (int i=1; i<=n; i++){
		cin>>c[i];
		if (c[i]==0){
			sum++;
		}
	}
	for (int i=0; i<(int)s.size(); i++){
		if (s[i]!='1'){
			flag=1;
		}
	}
	if (flag==0){
		int ans=1;
		for (int i=1; i<=n-sum; i++){
			ans=ans*i%_mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
