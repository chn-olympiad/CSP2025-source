#include<bits/stdc++.h>
using namespace std;
int n;
int k,a[500005],sl,pre[500005],maxx;
void ss(int x,int qj)
{
	if(x>=n)
	{
		maxx=max(maxx,qj);
	}
	for(int i=x;i<=n;i++)
	{
		int ab=pre[x-1]^pre[i];
		if(ab==k)
		{
			ss(i+1,qj+1);
		}
	}
	return;
}
int main()
{
	//freopen("xor6.in","r",stdin);
	//freopen("xor6.out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++)
		ss(i,0);
	cout<<maxx;
	return 0;
}

