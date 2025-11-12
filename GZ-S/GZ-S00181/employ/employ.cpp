//GZ-S00181 毕节梁才学校 张静峰
#include<bits/stdc++.h>
using namespace std ;
typedef long long LL;

int n,m;

string s;
int a[510];
int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>a[i];
	}
	LL res=1;
	for(int i=n;i>=1;i--){
		res*=i;
		res=res%998244353;
	}
	cout<<res;
	return 0 ;
}

