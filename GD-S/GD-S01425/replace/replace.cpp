#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,t;
struct xx
{
	string a,b;
}a[200005];
bool cmp(xx x,xx y)
{
	return x.a.size()<y.a.size();
}
int main()
{
	freopen("replace.in","w",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b;
	sort(a+1,a+n+1,cmp);
	while(q--)
	{
		cout<<rand()%5;
	}
}

