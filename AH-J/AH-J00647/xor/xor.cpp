#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	F;
	int n,k,h[500005],x[500005]{0},i,j,l,cnt=0;
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>h[i],x[i]=x[i-1]^h[i];
	for(i=1;i<=n;){
		bool f=1;
		for(j=i;j<=n&&f;++j){
			for(l=j;l>=i&&f;--l)
				if((x[j]^x[l-1])==k)f=0,++cnt;
		}
		i=j;
	}
	cout<<cnt<<endl;
	return 0;
}
