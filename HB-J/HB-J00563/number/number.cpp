#include <bits/stdc++.h>
using namespace std;
int a[1005]={},no=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			no++;
			a[no]=s[i]-'0';
		}
	}
	sort(a+1,a+no+1);
	for(int i=no;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
