#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],xb; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9') a[++xb]=int(s[i]-'0');
	sort(a+1,a+1+xb);
	for(long long i=xb;i>=1;i--)
		cout<<a[i];
	return 0;
}
