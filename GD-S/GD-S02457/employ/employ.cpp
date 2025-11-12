#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,ans,a[N],c[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=i;
	}
	do
	{
		int dq=0,zs=0;
		for(int i=1;i<=n;i++)
		{
			if(dq>=c[a[i]])
			{
				dq++;
				continue;
			}
			if(s[i-1]=='0') dq++;
			else zs++;
			if(zs>=m) break;
		}
		if(zs>=m) ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
