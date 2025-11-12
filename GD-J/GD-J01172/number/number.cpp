#include<bits/stdc++.h>
using namespace std;
string s,sa;
int a[10000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s) if(i<='9'&&i>='0') sa+=i;
	int n=sa.size();
	for(int i=0;i<n;i++) a[i]=sa[i]-'0';
	sort(a,a+n);
	for(int i=n-1;i>=0;i--) cout<<a[i];
	return 0;
 } 
