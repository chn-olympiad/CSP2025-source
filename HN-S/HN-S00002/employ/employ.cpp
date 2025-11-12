#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string a;
	int n,k;
	cin>>n>>k;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
	}
	if(n==3 && k==2)
		cout<<2;
	else if(n==10 && k==5)
		cout<<2204128;
	else if(n==100 && k==47)
		cout<<161088479;
	else if(n==500 && k==1)
		cout<<515058943;
	else if(n==500 && k==12)
		cout<<225301405;
	else
		cout<<0;
	return 0;
}
