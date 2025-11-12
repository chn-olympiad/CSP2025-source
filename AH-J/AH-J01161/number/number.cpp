#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000010],p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++p]=int(s[i]-'0');
	sort(a+1,a+p+1);
	for(int i=p;i>=1;i--)cout<<a[i];
	return 0;
}
