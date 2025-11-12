#include<bits/stdc++.h>
using namespace std;
struct hajimi{
	int st,en;
};
hajimi t;
vector<hajimi>faan;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0;
	cin>>n;
	int na=0;
	int dang=0;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=i;j++)
		{
			t.st=j;
			t.en=i;
			faan.push_back(t);
		}
	}
	int tmp=0;
	for(int i=0;i<faan.size();i++)
	{
		maxx=0;
		tmp=0; 
		for(int j=faan[i].st;j<=faan[i].en;j++)
		{
			tmp+=a[j];
			maxx=max(a[j],maxx);
		 } 
		if(tmp>maxx*2)
		{
			ans++;
			ans%=998244353;
		} 
	}			
	cout<<ans;
	return 0;
}
