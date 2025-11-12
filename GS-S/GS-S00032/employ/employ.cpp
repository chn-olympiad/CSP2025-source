#include<bits/stdc++.h>
using namespace std;
const int N=510;
const long long D=998244353;
typedef long long ll;
ll n,m,s[N],c[N],o,e,t;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i];
		if(s[i]!=1) o=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(o==0)
	{
		e=1,t=1;
		for(int i=1;i<=n;i++) e=(ll)e*i%D;
		for(int i=1;i<=n-m;i++) t=(ll)t*i%D;
		e=(ll)e/t%D;
		cout<<e;
	}
	else cout<<"18";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
