#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[200005],cnt=0;
	for(int i=0;i<=200005;i++)
	{
		a[i]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				cnt++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i+1])
			{
				cnt++;
				i++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
