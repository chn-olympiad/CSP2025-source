#include<bits/stdc++.h>
using namespace std;
string s;
int n,i;
char a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++)
	if(s[i]>='0'&&s[i]<='9')
	{n++;a[n]=s[i];}
	sort(a+1,a+1+n);
	for(i=n;i>0;i--)
	cout<<a[i];
	return 0;
}
