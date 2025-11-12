#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int n;
long long total=0;
int a[6000];
vector<int> v;
bool pd(int m,int sum,int maxlen)
{
	if(m<3)
		return false;
	if(sum<=maxlen*2)
		return false;
	return true;
}
void dfs(int t,int xvan,long long sum,string s,int max_len)
{
	//cout<<t<<" false "<<s<<endl;
	if(t==n+1)
	{
		if(pd(xvan,sum,max_len))
		{
			//cout<<s<<endl;
			total++;
			total%=998244353;
		}
		return;
	}
	dfs(t+1,xvan,sum,s,max_len);
	sum+=a[t];
	max_len=max(max_len,a[t]);
	xvan++;
	//s+=' ';
	//s+=(char)(t+'0');
	//cout<<t<<" true "<<s<<endl;
	dfs(t+1,xvan,sum,s,max_len);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0,"",0);
	cout<<total;
}
