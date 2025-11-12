#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000010; 
char a[MAXN],b[MAXN];
int n;
signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	for(int i=0;i<=MAXN;i++)b[i]=0;
	string s;
	cin>>s;
	n=s.length();
	int cur=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cur++;
			a[cur]=s[i];
		}
	}
	string las="";
	for(int i=1;i<=cur;i++)
	{
		char maxn=char(47);
		char ji;
		int lu;
		for(int j=1;j<=cur;j++)
		{
			if(!b[j])
			{
				ji=maxn;
				maxn=max(maxn,a[j]);
				if(ji!=maxn)lu=j;
			}
		}
		las+=maxn;
		b[lu]=1;
	}
	cout<<las;
}
