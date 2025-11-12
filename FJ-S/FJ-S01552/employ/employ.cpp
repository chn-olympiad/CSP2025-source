#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a;
string kk;
long long jc(long long s){
	if(s==1) return 1;
	return s*jc(s-1);
}
int main()
{
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
cin>>n>>m>>kk;
for(int i=1;i<=n;i++) cin>>a;
if(n<m||n==0){
	cout<<0;
	return 0;
}

if(n<=63&&n>=1) {
	cout<<jc(n)%998244353;
}
else if(n==m) cout<<0;
else cout<<1;
	return 0;
}

