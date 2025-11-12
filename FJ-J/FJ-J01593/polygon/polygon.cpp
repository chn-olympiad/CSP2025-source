#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,Mod=998244353;
int n,k,a[N],num,cnt1,cnt0;
bool flag;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];	
		if(a[i]!=1)
			flag=true;
	}
	if(!flag)
	{
		cout<<(n*n-(n-2)*(n+5)/2)%Mod;
		return 0;
	}
			
	return 0;
}
