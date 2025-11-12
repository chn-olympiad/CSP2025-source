#include<bits/stdc++.h>
using namespace std;
long long l,a[1000005];
string st;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>='0'&&st[i]<='9') a[++l]=int(st[i]-'0');
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--) printf("%lld",a[i]);
	return 0;
 } 
