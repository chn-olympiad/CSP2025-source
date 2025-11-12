#include<bits/stdc++.h>
using namespace std;

int n, k, ans;
int a[500005];

void QAQ(int l, int r, int cnt)
{
	if(l>r) return ;
	int i, v=cnt;
	for(i=l;i<=r;i++)
	{
		
		v ^= a[i];
		if(v==k)
		{
			ans++;
		}
		if(l==r) return ;
		if(i==l) QAQ(l+1, r, 0);
	}
	return ;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	QAQ(1, n, 0);
	cout<<ans;
	return 0;
}
