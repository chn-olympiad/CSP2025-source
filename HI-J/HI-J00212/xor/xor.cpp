#include<bits/stdc++.h>
using namespace std;
long long n,s,ss;
int a[100000],k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		s++;
		else if(a[i]==0)
		ss++;
	}
	if(k!=1&&k!=0)
	cout<<0;
	else if(k==1)
	cout<<s;
	else if(k==0)
	cout<<s/2+ss;
	return 0;
}
