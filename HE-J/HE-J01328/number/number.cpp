#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],o=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[o++]=s[i]-'0';
		}
	}
	o--;
	sort(a+1,a+1+o,greater<int>());
	for(int i=1;i<=o;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
