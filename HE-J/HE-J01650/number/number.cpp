#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int n[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >>s;
	int pos=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			n[pos]=s[i]-'0';
			pos++;
		}
	}
	sort(n,n+pos,cmp);
	for(int i=0;i<pos;i++)
		cout <<n[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
