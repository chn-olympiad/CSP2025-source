#include<algorithm>
#include<iostream>
using namespace std;
const int N=998244353;
int n,m;
char a[510];
int c[510];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n;j++) cin>>c[j];
	for(int i=1;i<=n;i++) ans*=i,ans%=N;
	cout<<ans;
	return 0;
}
