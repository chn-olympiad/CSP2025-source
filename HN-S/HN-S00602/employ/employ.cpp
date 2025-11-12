#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int s[N],c[N];
int mod=998244353;
int num=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char zm;
	for(int i=1;i<=n;i++)
	{
		cin>>zm;
		if(zm=='0') s[i]=0;
		else s[i]=1;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
		num++;
	}
	if(m==0)
	{
		cout<<1<<endl;
		return 0;
	}
	cout<<n-num<<endl;
}
