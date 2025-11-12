#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int MOD=998244353;
long long n,m,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<+n;i++)
		ans=(ans*i)%MOD;
	cout<<ans;
	return 0;
}