#include<iostream>
#include<string>
using namespace std;
int number[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	//cout<<sizeof(si)<<endl;
	for(int i=0;i<=sizeof(s)+5;i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			number[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=number[i];j++)
		printf("%d",i);
	}
}
//天灵灵，地灵灵，Devc++求你别抽风。
//不要让我的sizeof再炸了qwq 
