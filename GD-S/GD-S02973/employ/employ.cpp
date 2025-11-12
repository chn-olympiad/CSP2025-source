#include<bits/stdc++.h>
using namespace std;
int m,n;
string s;
int b[100000],a,ans,k,d,l;
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	l=s.size();
	for(int i=1;i<=n;i++) cin>>b[i];
	a=0;
	int c=n*(n-1)*(n-2);
	k=1,d=0;
	while(c--)
	{
		d=0,a=0,k=1,d=0;//d是录取人数，a是 
		for(int i=1;i<=n;i++)
		{
			if(d==m) 
			{
				ans++;
				break;
			}
			if(a<b[i]&&s[i-1]-'0'==1)
			{
				a=0; 
				d++;
			}
			else a++; 
		}
	}
	cout<<(ans%998244353)<<"\n";
	return 0;
}
