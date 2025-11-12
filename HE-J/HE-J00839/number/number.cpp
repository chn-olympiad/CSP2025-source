#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
string s;
int ans=0,a[N],b[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9'&&s.size()==1)
		{
			cout<<s[i];
			return 0;
		}
		if(s[i]=='9')
		{
			b[1]=9;
		}else if(s[i]=='8')
		{
			b[2]=8;
		}else if(s[i]=='7')
		{
			b[3]=7;
		}else if(s[i]=='6')
		{
			b[4]=6;
		}else if(s[i]=='5')
		{
			b[5]=5;
		}else if(s[i]=='4')
		{
			b[6]=4;
		}else if(s[i]=='3')
		{
			b[7]=3;
		}else if(s[i]=='2')
		{
			b[8]=2;
		}else if(s[i]=='1')
		{
			b[9]=1;
		}else if(s[i]=='0')
		{
			b[0]=0;
		}
	}
	if(b[1]==0)
	{
		cout<<b[2]<<b[3]<<b[4]<<b[5]<<b[6]<<b[7]<<b[8]<<b[9]<<b[0];
	}else if(b[2]==0)
	{
		cout<<b[1]<<b[3]<<b[4]<<b[5]<<b[6]<<b[7]<<b[8]<<b[9]<<b[0];
	}else if(b[3]==0)
	{
		cout<<b[1]<<b[2]<<b[4]<<b[5]<<b[6]<<b[7]<<b[8]<<b[9]<<b[0];
	}else if(b[4]==0)
	{
		cout<<b[1]<<b[2]<<b[3]<<b[5]<<b[6]<<b[7]<<b[8]<<b[9]<<b[0];
	}else if(b[5]==0)
	{
		cout<<b[1]<<b[2]<<b[3]<<b[4]<<b[6]<<b[7]<<b[8]<<b[9]<<b[0];
	}else if(b[6]==0)
	{
		cout<<b[1]<<b[2]<<b[3]<<b[4]<<b[5]<<b[7]<<b[8]<<b[9]<<b[0];
	}else if(b[7]==0)
	{
		cout<<b[1]<<b[2]<<b[3]<<b[4]<<b[5]<<b[6]<<b[8]<<b[9]<<b[0];
	}else if(b[8]==0)
	{
		cout<<b[1]<<b[2]<<b[3]<<b[4]<<b[5]<<b[6]<<b[7]<<b[9]<<b[0];
	}else if(b[9]==0)
	{
		cout<<b[1]<<b[2]<<b[3]<<b[4]<<b[5]<<b[6]<<b[7]<<b[8]<<b[0];
	}else if(b[0]==0)
	{
		cout<<a[1]<<b[2]<<b[3]<<b[4]<<b[5]<<b[6]<<b[7]<<b[8]<<b[9];
	}
	return 0;
}
