#include<bits/stdc++.h>
using namespace std;
const int N=600,MOD=998244353;
int n,m,a[N],sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		sum=(sum*i)%MOD;
	cout<<sum;
	return 0;
}
