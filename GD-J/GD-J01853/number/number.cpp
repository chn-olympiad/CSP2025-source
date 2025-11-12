#include<bits/stdc++.h>
using namespace std;
string s;
string a[1010011]; 
long long n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[i]=s[i];
	}	
	sort(a,a+n);
	for(int i=n;i>=0;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
}
//保底得分，检查！！！ 
