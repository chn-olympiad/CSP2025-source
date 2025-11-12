#include<bits/stdc++.h>
using namespace std;
long long a[100000001],cnt;
string n;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++)
		if(n[i]>='0'&&n[i]<='9')
			a[cnt++]=n[i]-'0';
	sort(a,a+cnt,cmp);
	if(a[0]==0)
		cout<<"0";
	else
		for(int i=0;i<cnt;i++)
			cout<<a[i];
	return 0;
}
