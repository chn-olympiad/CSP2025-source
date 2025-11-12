#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,t=0;
int a;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		t= (t ^ a) ;
		if(t==k)
		{
			cnt++;
			t=0;
		}
	}
	cout<<cnt;
}
