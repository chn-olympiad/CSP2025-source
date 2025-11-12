#include<iostream>
#include<algorithm>
using namespace std;
string s;
int y[1000003]={},i=0;
bool cmd(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int k=0;s[k]!='\0';k++)
	{
		if(s[k]-'0'>=0&&s[k]-'0'<=9)
		{
			y[i]=s[k]-'0';
			i++;
		}
	}	
	sort(y,y+i,cmd);
	for(int k=0;k<i;k++)
	{
		cout<<y[k];
	}
	return 0;
 } 
