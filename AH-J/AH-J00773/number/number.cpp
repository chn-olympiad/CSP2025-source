#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
const LL N=1e6+5;
LL a[N];
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL cnt=0;
	LL len=s.size();
	for(LL i=0;i<len;i++){
		if(isdigit(s[i])) a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	for(LL i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
