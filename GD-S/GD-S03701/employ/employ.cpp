#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510],c[510],l,h;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		a[i]=int(c-'0');
		l+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int o;
		cin>>o;
		if(o!=0)
		{
			h++;
			c[h]=o;
		}
	}
	sort(c+1,c+h+1); 
	if(l<m||h<m)
	{
		cout<<0;
		return 0;
	}
	long long s=1;
	for(int i=2;i<=h;i++)
		s=(s*i)%mod;
	for(int i=2;i<=(n-h);i++)
		s=(s*i)%mod;
	cout<<s;
	return 0;
}
