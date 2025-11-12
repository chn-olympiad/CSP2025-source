#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+50;
int a[N],l;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++) 
	{
		if(s[i]>='0'&&s[i]<='9') a[++l]=s[i]-'0';
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--) cout<<a[i];
	return 0;
}

