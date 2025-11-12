#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string s;
const int N=1e6+10;
int a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);//正式提交 
	cin>>s;
	int len=s.size(),id=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')//是数字就加入a数组 
		{
			int num=s[i]-'0';
			a[++id]=num;
		}
	}
	sort(a+1,a+id+1,greater<int>());//从大到小 
	for(int i=1;i<=id;i++)
	{
		cout<<a[i];
	}
	return 0;
}//期望100pts 