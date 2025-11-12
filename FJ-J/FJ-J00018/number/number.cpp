#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[n++]=s[i]-'0';
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++)
	cout<<a[i];
	return 0;
}
