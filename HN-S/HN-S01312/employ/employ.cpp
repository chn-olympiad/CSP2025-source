#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;
int n,m,a[100005],k;
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)k*=i;
	cout<<rand()%k%M;
	return 0;
}
