#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,a[N],k,cnt=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==k){
		cnt++;
		a[1]=0;
	}
	for(int i=2;i<=n;i++)
	{
		if((a[i-1]^a[i])<=k)
		{
			a[i]=a[i]^a[i-1];
		}
		if(a[i]==k) 
		{
			cnt++;
			a[i]=0;
		}
	}
	cout<<cnt;
	return 0;
}
