#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char c[1000001]="";
string ans;
int comp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin >> s;
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans+=s[i];
			//cout << "½øÈë" << s[i];
			cnt++;
		}
	}
	for(int i = 0 ; i < s.length() ; i++)
	{
		c[i]=ans[i];
	}
	sort(c,c+cnt,comp);
	cout << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
