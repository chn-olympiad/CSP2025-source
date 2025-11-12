#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct yi
{
	int len,x1,x2;
}sh[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		//cout << 1 << ' ';
		string x1,x2;
		cin >> x1 >> x2;
		//cout << x1 <<' ' << x2  << endl;
		int len=x1.length();
		int k=0,j1=0;
		for(int j=0;j<len;j++)
		{
			if(x1[j]=='b')
			{
				k=j;
				break;
			}
		}
		for(int j=0;j<len;j++)
		{
			if(x2[j]=='b')
			{
				j1=j;
				break;
			}
		}
		sh[i].len=len;sh[i].x1=k;sh[i].x2=j1;
		//cout << sh[i].x1 << ' ' << sh[i].x2 << endl;
	}
	while(q--)
	{
		string x1,x2;
		cin >> x1 >> x2;
		int len=x1.length();
		int k=0,j1=0;
		for(int j=0;j<len;j++)
		{
			if(x1[j]=='b')
			{
				k=j;
				break;
			}
		}
		for(int j=0;j<len;j++)
		{
			if(x2[j]=='b')
			{
				j1=j;
				break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(k-j1!=sh[i].x1-sh[i].x2) continue;
			int x1=sh[i].len-sh[i].x1;
			int x2=sh[i].len-sh[i].x2;
			if(x1<=len-k && x2<=len-j1)
			{
				ans++;
			} 
		}
		cout << ans << "\n";
	}
	return 0;
}
