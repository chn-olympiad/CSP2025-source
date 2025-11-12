#include<bits/stdc++.h>
using namespace std;
string s,ans,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
long long len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0')
		{
			a0=a0+'0';
		} 
		else if(s[i]=='1')
		{
			a1=a1+'1';
		}
		else if(s[i]=='2')
		{
			a2=a2+'2';
		}
		else if(s[i]=='3')
		{
			a3=a3+'3';
		}
		else if(s[i]=='4')
		{
			a4=a4+'4';
		}
		else if(s[i]=='5')
		{
			a5=a5+'5';
		}
		else if(s[i]=='6')
		{
			a6=a6+'6';
		}
		else if(s[i]=='7')
		{
			a7=a7+'7';
		}
		else if(s[i]=='8')
		{
			a8=a8+'8';
		}
		else if(s[i]=='9')
		{
			a9=a9+'9';
		}
	}
	ans=a9+a8+a7+a6+a5+a4+a3+a2+a1+a0;
	cout<<ans;
	return 0;
}
