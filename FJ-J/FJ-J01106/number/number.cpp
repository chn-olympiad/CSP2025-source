#include<bits/stdc++.h> 
using namespace std;
long long num[1000005],cnt=1,len;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++) 
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[cnt]=s[i]-'0';
			cnt++;
		}
	}
	cnt--; 
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<num[i];
	return 0;
}
