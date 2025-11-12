#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5000+5;
int n;
int cnt;
int a[N];
int s[N];

void dfs(int st,int sum,int maxn)
{
	if(sum>2*maxn) cnt++;
	
	for(int i=st;i<=n;i++)
	{
		dfs(i+1,sum+a[i],max(maxn,a[i]));
	} 
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i] = s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		
		return 0;
	}
	
	dfs(1,0,0);
	
	cout<<cnt;
	return 0;
}
