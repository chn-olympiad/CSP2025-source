#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000001];
bool judge(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long cnt=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,judge);
	if(a[1]==0)
	{
		cout<<0<<endl;
		return 0;	
	}	
	else
	{
		for(int i=1;i<=cnt;i++)
		{
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
