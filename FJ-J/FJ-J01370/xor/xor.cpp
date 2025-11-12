#include <bits/stdc++.h>
using namespace std;
#define N 500010
int n,k,f[N],head=0,ans=0;
map<int ,int>a;
int main()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		if(f[i]==k)
		{
			ans++;
			head=i;
		}
		f[i]=f[i]^f[i-1];
		if(f[i]==k&&head==0)
		{
			ans++;
			head=i;
		}
		if(a[k^f[i]]>=head&&a[k^f[i]]!=0)
		{
			ans++;
			head=i;
		}
		a[f[i]]=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
