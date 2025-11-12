#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int a[1000005],h,l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[++h]=s[i]-'0';
	}
	sort(a+1,a+h+1);
	while(h>1&&a[h]==0) h--;
	for(int i=h;i>0;i--) cout<<a[i];
	return 0;
}
