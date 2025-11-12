#include<iostream>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s0="";
	string s1="";
	string s2="";
	string s3="";
	string s4="";
	string s5="";
	string s6="";
	string s7="";
	string s8="";
	string s9="";
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='0'){
				s0+=s[i];
			}else if(s[i]=='1')	{
				s1+=s[i];
			}else if(s[i]=='2')	{
				s2+=s[i];
			}else if(s[i]=='3')	{
				s3+=s[i];
			}else if(s[i]=='4')	{
				s4+=s[i];
			}else if(s[i]=='5')	{
				s5+=s[i];
			}else if(s[i]=='6')	{
				s6+=s[i];
			}else if(s[i]=='7')	{
				s7+=s[i];
			}else if(s[i]=='8')	{
				s8+=s[i];
			}else if(s[i]=='9')	{
				s9+=s[i];
			}
		}
	}
	string sz="";
	sz=s9+s8+s7+s6+s5+s4+s3+s2+s1+s0;
	cout<<sz<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
290es1q0
*/
