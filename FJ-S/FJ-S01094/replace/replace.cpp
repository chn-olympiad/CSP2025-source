#include<bits/stdc++.h>
using namespace std;
string a[200005][10];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	while(q--)
	{
		string ta,tb;
		cin>>ta>>tb;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]==ta&&a[i][2]==tb) sum++;
		}
		string ssa,ssb;
		for(int i=0;i<ta.size();i++)
		{
			if(ta[i]!=tb[i]) 
			{
				ssa+=ta[i];
				ssb+=tb[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]==ssa&&a[i][2]==ssb) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
