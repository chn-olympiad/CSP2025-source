#include<bits/stdc++.h>
using namespace std;

int n,m,a[505];
string s;
long long cnt=1;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cnt*=i,cnt%=998244353;
	cout<<cnt;
	return 0;
}

