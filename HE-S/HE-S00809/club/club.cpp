#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int a,b,c;
}s[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sum=0;
	cin>>t;
	while(t--)
	{
		int n,a1,a2,a3;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			sum+=max(s[i].c,(s[i].a,s[i].b));
		}
	}
	cout<<sum;
	return 0;
}
