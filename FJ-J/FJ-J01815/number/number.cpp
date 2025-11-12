#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i];i++)
		if(s[i]>='0'&&s[i]<='9') a[++p]=s[i]-'0';
	sort(a+1,a+p+1);
	for(int i=p;i>=1;i--)
		cout<<a[i];
	return 0;
}
