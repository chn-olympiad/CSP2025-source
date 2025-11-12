#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s0,s1,s2,s3,s4,s5,s6,s7,s8,s9;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			if((s[i]-'0')==0)
				s0+='0';
			if((s[i]-'0')==1)
				s1+='1';
			if((s[i]-'0')==2)
				s2+='2';
			if((s[i]-'0')==3)
				s3+='3';
			if((s[i]-'0')==4)
				s4+='4';
			if((s[i]-'0')==5)
				s5+='5';
			if((s[i]-'0')==6)
				s6+='6';
			if((s[i]-'0')==7)
				s7+='7';
			if((s[i]-'0')==8)
				s8+='8';
			if((s[i]-'0')==9)
				s9+='9';
		}
	}
	if(s9==""&&s8==""&&s7==""&&s6==""&&s5==""&&s4==""&&s3==""&&s2==""&&s1=="")
		cout<<"0";
	else
		cout<<s9<<s8<<s7<<s6<<s5<<s4<<s3<<s2<<s1<<s0;
	return 0;
}
