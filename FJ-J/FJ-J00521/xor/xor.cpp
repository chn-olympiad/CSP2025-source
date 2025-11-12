#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n,k,a[N],ma=0,p;
stack<int> st;
int fer(int x)
{
	while(x > 0)
	{
		int t = x % 2;
		st.push(t);
		x /= 2;
	}
	while(!st.empty())
	{
		return st.top();
		st.pop();
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++)
	{
		if(a[i] == 1)
		{
			p++;
		}
	}
	if(p == n)
	{
		cout<<0<<endl;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j++)
		{
			stack<int> st;
			if(fer(a[i]) | fer(a[j]) == k)
			{
				ma = max(ma,j - i);
			}
		}
	}
	cout<<ma-a[k+1]<<endl;
	return 0;
}
