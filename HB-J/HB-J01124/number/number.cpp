#include<bits/stdc++.h>
using namespace std;
bool cp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int num[1000005]={0};
	int cnt=0;
	cin>>s;
	for(long unsigned int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int n=s[i]-'0';
			num[cnt]=n;
			cnt++;
		}
	}
	sort(num,num+cnt,cp);
	for(int i=0;i<cnt;i++)
	{
		cout<<num[i];
	}
	return 0;
}
