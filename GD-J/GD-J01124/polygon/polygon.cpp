#include<iostream>
using namespace std;
int a[5005],n,res;
bool v[5005];
void dfs(int d)
{
	if(d>n)
	{
		int max=0,sum=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(v[i])
			{
				if(a[i]>max) max=a[i];
				sum+=a[i];
				cnt++;
			}
		if(cnt>=3 && sum>max*2) res=(res+1)%998244353;
		return;
	}
	v[d]=true;
	dfs(d+1);
	v[d]=false;
	dfs(d+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d",res);

	fclose(stdin); fclose(stdout);
	return 0;
}
