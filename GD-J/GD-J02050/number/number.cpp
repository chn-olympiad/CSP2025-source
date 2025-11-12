#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size()-1;
	for(int i=0;i<=len;i++) if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--) printf("%d",a[i]);
} 
