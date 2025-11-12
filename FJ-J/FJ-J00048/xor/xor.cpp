#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],m[1100005],ans,r=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=1100000;i++)
	{
		m[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(m[s[i]^k]+1>r)
		{
			ans++,r=i;
//			cout<<m[s[i]^k]+1<<' '<<i<<endl;
		}
		m[s[i]]=i;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<s[i]<<' ';
//	}
//	cout<<endl;
	cout<<ans;
	return 0;
}

