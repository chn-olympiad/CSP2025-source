#include<bits/stdc++.h>

using namespace std;

int ans[1000010];

int main()
{

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int i;
	int len=0;
	//cout<<"AE"<<endl;
	for(i=0;i<s.length();i++)
	{
		//cout<<"A"<<endl;
		if((s[i]>='0')&&(s[i]<='9'))
		{
			ans[len]=s[i]-'0';
			len++;
		}
	}
	sort(ans,ans+len);
	while((len>0)&&(ans[len-1]==0))
	{
		len--;
	}
	if(len==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(i=len-1;i>=0;i--)
	{
		cout<<ans[i];
	}

	return 0;
}
