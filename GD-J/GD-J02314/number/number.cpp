#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

string s;
int ch[N];

bool cmp(int a,int b)
{
	return b<a;
}

int main()
{

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);			

	int cnt=0;

	cin>>s;

	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))ch[++cnt]=s[i]-'0';
	}

	sort(ch+1,ch+1+cnt,cmp);
                        
	for(int i=1;i<=cnt;i++)
	{
		cout<<ch[i];	
	}
	return 0;
}

