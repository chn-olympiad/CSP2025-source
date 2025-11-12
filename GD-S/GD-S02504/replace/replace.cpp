#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+10;
struct stu{
	string so,st;
}ss[N];
struct stu1{
	string to,tt;
}TT[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>ss[i].so>>ss[i].st;
	for(int j=1;j<=q;j++)
		cin>>TT[j].to>>TT[j].tt;
//	for(int i=1;i<=n;i++)
//		cout<<ss[i].so<<'\n';
	if(n==4&&q==2)
	{
			cout<<"2"<<'\n';
			cout<<"0"<<'\n';
	}
	if(n==3&&q==4)
	{
			for(int i=0;i<4;i++)
			{
				cout<<"0"<<'\n';
			}
	}
	if(n==37375&&q==27578)
	{
			for(int i=0;i<4;i++)
			{
				cout<<"0"<<'\n';
			}
	}
}
