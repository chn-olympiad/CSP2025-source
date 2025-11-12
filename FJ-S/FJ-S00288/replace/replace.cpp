#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
struct str{
	string s,ss;
}a[N],b[N];
int n,q;
int found(int i)
{
	for (int j=1;j<=n;j++)
		if (a[j].s==b[i].s)
			return j;
	return (-1);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>a[i].s>>a[i].ss;
	for (int i=1;i<=q;i++)
		cin>>b[i].s>>b[i].ss;
	for (int i=1;i<=q;i++)
	{
		int f=found(i);
		if (f==(-1)){
			cout<<0;}
		
	}
	return 0;
}

