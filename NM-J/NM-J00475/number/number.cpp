#include<bits/stdc++.h>
using namespace std;
string s;
int num[1001001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int len=0;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num[++len]=s[i]-'0';
	sort(num+1,num+len+1,cmp);
	int flag=1;
	for(int i=1;i<=len;i++)
	{
		if(i==1)
		{
		    if(num[i]!=0)
		    {
		    	cout<<num[i];
		    	flag=0;
			}
		}
		else
		{
			if(flag==1&&num[i]!=0)
			{
				cout<<num[i];
				flag=0;
			}
			else if(flag==0)
                cout<<num[i];
		}
	}
	if((len==1&&num[1]==0)||(len!=0&&flag==1))
		cout<<0;
	return 0;
}
