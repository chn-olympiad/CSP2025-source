#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5010;
long long a[maxn];
long long ans=0,n;
void dfs(int k,long long lei,long long maxx)
{
		if(k>n)return;
		maxx=max(maxx,a[k]);
		lei+=a[k];
		if(lei>maxx*2)ans++;
		for(int kk=k+1;kk<=n;kk++)
		dfs(kk,lei,maxx);
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int l=j+1;l<=n;l++)
			dfs(l,a[i]+a[j],max(a[i],a[j]));
		}
	}
	cout<<ans;
    return 0;
}
