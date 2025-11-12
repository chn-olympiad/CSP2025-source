#include <bits/stdc++.h>
using namespace std;
int c[501],m,n;
string s;
long long ans=1;
void solve(int a,int b){
	int ac=0,ref=0;
	for(int i=a;i<n;++i){
		for(int q=b+1;q<n;++q){
			solve(i,q);
		}
	}
	for(int i=0;i<n;++i){
		if(s[i]=='0'||ref>=c[i])
			ref++;
		else
			ac++;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;//1145141919810
	for(int i=0;i<n;++i)
		cin>>c[i];
	for(int i=1;i<=n;++i)
		ans*=i;
	cout<<ans%998244353;
	return 0;
}
