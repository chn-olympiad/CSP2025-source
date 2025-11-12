#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e6+10;
LL a[N];
bool cmp(const LL &x,const LL &y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1,s2;
	cin>>s;
	LL l=s.size();
	for(LL i=0;i<l;i++)
	{
		if(s[i]<='9'&&s[i]>='0') s1+=s[i];
	}
	for(LL i=1;i<=l;i++)
	{
		a[i]=s1[i-1];
	}
	sort(a+1,a+1+l,cmp);
	for(LL i=1;i<=l;i++) cout<<char(a[i]);
	return 0;
}
