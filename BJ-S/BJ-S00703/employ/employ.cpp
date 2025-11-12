#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n];
	for(int i=0;i<n;i++)
		cin>>c[i];
	int ok=1;
	for(int i=0;i<s.size();i++)
		if(s[i]==1)
		{
			ok=0;
			break;
		}
	if(ok==1)
		cout<<0;
	return 0;
}