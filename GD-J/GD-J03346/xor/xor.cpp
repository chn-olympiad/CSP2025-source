#include<bits/stdc++.h>
using namespace std;
int a[1000000]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i],sum+=a[i];
	if(k==0 or k==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		if(a[i]==k) cnt++;
		cout<<cnt;
		return 0;
	}
	cout<<ceil(sum/n)+1;
}//CCF is great(too diffcult!!!)

