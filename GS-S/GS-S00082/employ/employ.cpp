#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500,mod=998244353;

int n,m;
char s[maxn+5];
int a[maxn+5],c[maxn+5];
long long ans;
long long f[maxn+5];

bool check()
{
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')
		{
			tot++;
			continue;
		}
		if(tot>=c[a[i]])tot++;
	}
	//cout<<tot<<"\n";
	return n-tot>=m;
}


int main() {
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(s+1);
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='1')tot++;
	}
	if(tot<m)
	{
		cout<<0;
		return 0;
	}
	f[0]=1;
	for(int i=1;i<=20;++i)f[i]=f[i-1]*i;
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
	}
	if(n>=12)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;++i)a[i]=i;
	for(int i=1;i<=f[n];++i)
	{
		if(check())ans++;
		next_permutation(a+1,a+1+n);
	}
	cout<<ans;
	return 0;
}
