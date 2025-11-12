#include <bits/stdc++.h>
using namespace std;
struct node
{
	string x,y;
}a[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s,t;
		cin>>s>>t;
		a[i]={s,t};
	}
	while(q--)
	{
		long long sum=0;
		string s,t;
		cin>>s>>t;
		for(int i=1;i<=n;i++)
		{
			int place=s.find(a[i].x);
			if(place!=-1)
			{
				string ans=(s.substr(0,place)+a[i].y+s.substr(place+a[i].x.size(),s.size()-(place+a[i].x.size())+1));
				if(ans==t)
				{
					sum++;
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
