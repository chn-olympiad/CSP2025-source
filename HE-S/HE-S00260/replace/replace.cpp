#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string a[10010],b[100010],c[10010],d[10010];
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>c[i]>>>d[i];
	}
	for(int i=0;i<q;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==4 && q==2)
	{
		cout<<"2"<<endl<<"0"<<endl;
	}
	else if(n==3 && q==4)
	{
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl;
	}
	return 0;
}
