#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],js=0;
long long sum=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	return 0;
}
