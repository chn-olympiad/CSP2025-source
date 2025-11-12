#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>

using std::min;
using std::max;
using std::cin;
using std::cout;
using std::sort;

const int N=505,M=998244353;

int n,m,c[N],C[N][N];
string s;
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	long long ans=C[n][m];
	for(int i=1;i<=m;i++) ans=(ans*i)%M;
	cout<<ans<<'\n';
	return 0;
}
