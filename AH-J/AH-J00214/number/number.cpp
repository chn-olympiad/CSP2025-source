#include<bits/stdc++.h>
using namespace std;
int wei=1;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a[1000001];
	for(int i=0;i<=s.size();i++)
	if(s[i]<='9'&&s[i]>='0')
    {
		if(s[i]=='0')
		a[wei]=0;
		else if(s[i]=='1')
		a[wei]=1;
		else if(s[i]=='2')
		a[wei]=2;
		else if(s[i]=='3')
		a[wei]=3;
		else if(s[i]=='4')
		a[wei]=4;
		else if(s[i]=='5')
		a[wei]=5;
		else if(s[i]=='6')
		a[wei]=6;
		else if(s[i]=='7')
		a[wei]=7;
		else if(s[i]=='8')
		a[wei]=8;
		else if(s[i]=='9')
		a[wei]=9;
		wei++;
	}//a[wei]=29010
	wei--;
	sort(a+1,a+1+wei);
	for(int i=wei;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

