#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n,m;
string st[N][2],re[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i][0]>>st[i][1];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>re[i][0]>>re[i][1];
		if(sizeof(re[i][0])!=sizeof(re[i][1]))cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

