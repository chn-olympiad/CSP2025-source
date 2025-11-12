#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5*100005;
int cnt;
int ans;
int a[N];
int i=1;
bool flag=false;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(k==1)
	{
		int sum=a[1];
		for(int i=1;i<=n;i++)
		{
			if(sum!=a[i]) ans++,sum=a[i+1];
		}
		cout<<ans;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) ans++;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=1)
			{
				cout<<ans;
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			cout<<n/2;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

