#include<bits/stdc++.h>
using namespace std;
string s;
int a[10005],cnt=0;
char b[100005];
bool cmp(int a,int b)
{
	return a> b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int num=s.size();
	for(int i=0;i<s.size();i++)
	{
		b[i]=s[i];
	}
	for(int i=0;i<num;i++)
	{
		if(b[i]>='0' && b[i]<='9')
		{
			a[cnt]=b[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
