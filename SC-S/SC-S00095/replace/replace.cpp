#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,q;
struct node
{
	string s1,s2;
};
node a1[N];
node a2[N];
int main()
{
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin.tie(0);cout.tie(0);
//============================================================================
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
		cin>>a1[i].s1>>a1[i].s2;
	for(int j=1;j<=q;j++)
		cin>>a2[j].s1>>a2[j].s2;
	for(int i=1;i<=q;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if(a1[i].s1==a2[j].s1&&a1[i].s2==a2[j].s2) sum++;
		}
		cout<<sum<<"\n";
	}
	return 0;
} 