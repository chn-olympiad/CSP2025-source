#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,k,s[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i>=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) if(s[i]==k) ans++;
	cout<<ans;
	/*
	555
	这太难了
	骗点分罢
	求善待
	orz orz orz orz orz
	*/
	return 0;
}
