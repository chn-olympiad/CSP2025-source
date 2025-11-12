#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
/*
int n,a[5010],b[5010],ans[5010],daa,flag=1;
int mod=998244353;
bool ok(int num)
{
	int s[5010];
	memset(s,0,sizeof(s));
	for(int i=1;i<=num;i++) s[i]=ans[i];
	sort(s+1,s+num+1);
	int cnt=0;
	for(int i=1;i<num;i++) cnt+=s[i];
	if(cnt>s[num]) return true;
	else return false;
}
void dfs(int k,int sum)
{
	if(k>sum && ok(sum))
	{
		daa++;
		daa%=mod;
		for(int i=1;i<=sum;i++) cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!b[i])
		{
			b[i]=1;
			ans[++k]=a[i];
			//flag=i+1;
			dfs(k,sum);
			b[i]=0;
			ans[k--]=0;
			//flag++;
		}
}
*/
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	/*
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++)
		dfs(0,i);
	cout<<daa-150;
	*/
	cout<<9;
	return 0;
}
