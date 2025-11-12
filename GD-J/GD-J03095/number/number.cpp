#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m;
int a[1000005];
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(long long i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++m]=s[i]-'0';
	sort(a+1,a+m+1,cmp);
	for(long long i=1;i<=m;i++)
		cout<<a[i];
	return 0;
 } 
