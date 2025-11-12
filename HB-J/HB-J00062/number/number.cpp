#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],k=1,ans,n;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[k++]=int(s[i]-'0');
	}
	sort(a+1,a+k,cmp);
	if(a[1]==0)
		cout<<0;
	else
	{
		for(int i=1;i<k;i++)
			cout<<a[i];
	}
	return 0;
}
