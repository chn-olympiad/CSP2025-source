#include<bits/stdc++.h>
using namespace std;

int n,m,patient[505],flag;
string dif;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>dif;
	for(int i=1;i<=n;i++){
		cin>>patient[i];
	}
	for(int i=0;i<n;i++)
	{
		if(dif[i]=='1')continue;
		else if(dif[i]=='0')flag=1;
	}
	if(flag==0)cout<<0;
	return 0;
}
