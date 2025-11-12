#include <iostream>
#include <cstdio>
using namespace std;

char str[100001]="";//输入字符，长度小于等于100000 
char s[10]={'9','8','7','6','5','4','3','2','1','0'};//10个数字的集 
int output=0;//输出的数值 

int main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	
	cin >> str;
	
    //先排序，后相加 
	
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=99999;j++)
		{
			if(str[j]==s[i])
			{
				output*=10;
				output+=9-i;
			}
		}
	}
	
	cout << output;
	
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
}