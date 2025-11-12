#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
bool f[1024*1024+5];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=a[i]^a[i-1];
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(f[a[i]^k])
		{
			cnt++;
			memset(f,0,sizeof(f));
		}
		f[a[i]]=1;
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
