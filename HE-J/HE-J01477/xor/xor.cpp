#include<bits/stdc++.h>
using namespace std;
long long a,b,n[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		scanf("%d",&n[i]);
	}
	sort(n,n+a);
	if(b==0)
	{
		if(a==2&&n[0]==1&&n[1]==1)
		cout<<1;
		else
		{
			if(a==1)
			{
				cout<<0;
			}
		}
	}
	else
	{
		if(b>n[1])
		{
			cout<<b-(b-n[a-2]);
		}
		if(b<n[1])
		{
			cout<<n[a-n[a-1]]-b;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
