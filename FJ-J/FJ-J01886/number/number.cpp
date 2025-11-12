#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int a[1000010];
int m=1;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++)
	{
		
		if(n[i]>='0'&&n[i]<='9') 
		{
			a[m++]=n[i]-'1'+1;
		}
	}
	m--;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
