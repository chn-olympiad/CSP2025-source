#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int m[1000005],t=0;
bool comp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);	
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			m[t]=s[i]-'0';
			t++;
		}
	}
	sort(m,m+t+1,comp);
	for(int i=0;i<t;i++)
	{
		cout<<m[i];
	}
	return 0;
} 