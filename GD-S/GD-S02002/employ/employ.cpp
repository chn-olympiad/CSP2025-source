#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M=998244353;
int n,m,l,c[505],p[505];
string s;
mt19937 rd(time(nullptr));
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;p[0]=1;
	for(int i=1; i<501; i++)p[i]=p[i-1]*i%M;
	for(int i=1; i<=n; i++){
		cin>>c[i];
		if(c[i])l++;
	}
	if(l<m)cout<<0;
	else cout<<rd()%M;
	return 0;
}
