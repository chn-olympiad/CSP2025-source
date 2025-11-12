#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,a[500005],s,ct,q,t;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0) s++;
	}
	if(k==0)
	{
		cout<<s;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
