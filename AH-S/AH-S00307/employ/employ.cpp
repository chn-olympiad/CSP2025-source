#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[510];
bool s[510];
string tmp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>tmp;
	for(int i=0;i<n;i++){
		s[i]=tmp[i]-'0';
		if(s[i])k++;
	}
	for(int i=0;i<n;i++)cin>>a[i];
	long long t=1;
	for(int i=2;i<=k;i++){
		t%=998244353;
		t*=i;
	}
	cout<<t;
	return 0;
}
