#include<bits/stdc++.h>
using namespace std;
int n,k,t1,t2;
long long s;
int a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		t1=a[i];
		for(int j=i;j<=n;j++)
		{
			t1^=a[j];
			if(t1==k) s++;
		}
	}
	cout<<s;
}

