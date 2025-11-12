#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000001],t;
bool ll(int a,int b){return a>b;}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;int p=0,pp=0;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-48;
	sort(a+1,a+1+t,ll);
	for(int i=1;i<=t;i++) if(a[i]!=0) pp=1;
	if(pp==1) for(int i=1;i<=t;i++) cout<<a[i];
	else cout<<0;	
	return 0;
 } 
