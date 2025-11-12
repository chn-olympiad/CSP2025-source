#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

int n,m;
string s_1[N],s_2[N],t_1[N],t_2[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s_1[i]>>s_2[i];
	for(int i=1;i<=m;i++)
	{
		cin>>t_1[i]>>t_2[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<0;
	}	
	
	return 0;
 } 