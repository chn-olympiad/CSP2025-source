#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin); 
	//就这样算了吗，我不甘心
	//不会收手，下次一定到我
	//断开节奏,要写的在最后
	//仰望星空 怀念过往6年的编程就这样结束了吗
	//写不尽却...
	//希望最后一次考试能上200分
	//三人行 于我何加焉 
	//freopen("number.out","w",stdout);
	string a;
	cin>>a;
	char s[1000001];
	int ss=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			s[ss]=char((a[i]));
			ss++;
		}
		
	}
	sort(s,s+ss);
	for(int i=ss-1;i>=0;i--)
	{
		cout<<int(s[i])-48;
	}
	freopen("number.out","w",stdout);
	return 0;
}
