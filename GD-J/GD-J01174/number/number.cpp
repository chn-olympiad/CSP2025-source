#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//bool cmp(int x,int y){
//	return x>y;
//}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//基数排序法
	string s;
	long long st[10]={};
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]=='0')st[0]++;
		if(s[i]=='1')st[1]++;
		if(s[i]=='2')st[2]++;
		if(s[i]=='3')st[3]++;
		if(s[i]=='4')st[4]++;
		if(s[i]=='5')st[5]++;
		if(s[i]=='6')st[6]++;
		if(s[i]=='7')st[7]++;
		if(s[i]=='8')st[8]++;
		if(s[i]=='9')st[9]++;
	}
	for(int j=9;j>=0;j--)
	{
		while(st[j]!=0) 
		{
			cout<<j;
			st[j]--;
		}
    }
	
//  //sort方法(大样例不可用） 
//	string s;
//	int st[1000000]={};
//	cin>>s;
//	int i=0,j=0;
//	while (i<s.size())
//	{
//		if('0'<=s[i] && s[i]<='9')
//		{
//			st[j]=s[i]-'0';
//			j++;
//		 } 
//		i++;
//	}
//	sort(&st[0],&st[j],cmp);
//	for(int e;e<j;e++) cout<<st[e];
	return 0;
 } 
