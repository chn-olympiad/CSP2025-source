#include<bits/stdc++.h>
using namespace std;
//定义一个字符串
string s; 
//定义数组
int a[10]; 
string num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//输入
	cin>>s;
	//获取字符串长度
	int len;
	len=s.size();
	//遍历字符串 
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int u=s[i]-'0';
			a[u]++;
		}
	}
	//验证输出
//	for(int i=0;i<10;i++)
//	{
//		cout<<i<<" "<<a[i]<<endl;
//	}
	//开始组建变量
	int y=0;//表示下标
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			num[y]=i+'0';
			y++;
			a[i]--;
		}
	}
	//输出
	for(int i=0;i<y;i++)
	{
		cout<<num[i]-'0';
	}
	
	
	
	return 0;
	//保存时记得解注释 
}
