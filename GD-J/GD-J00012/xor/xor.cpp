#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k,a[N],flag=1,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				cnt++;
		cout<<cnt;
	}
	else if(k==1) 
	{
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				cnt++;
		cout<<cnt;
	}
	else
		cout<<0;
}
